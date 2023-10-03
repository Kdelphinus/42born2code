#include "../includes/ServerOperator.hpp"

ServerOperator::ServerOperator(ServerMap &serverMap, LocationMap &locationMap)
    : _serverMap(serverMap), _locationMap(locationMap) {}

ServerOperator::~ServerOperator() {}

void ServerOperator::run() {
  Kqueue kq;
  if (kq.init(_serverMap) == EXIT_FAILURE) return;

  struct kevent *currEvent;
  int eventNb;
  while (1) {
    eventNb = kq.countEvents();
    kq.clearCheckList();

    for (int i = 0; i < eventNb; ++i) {
      currEvent = &(kq.getEventList())[i];
      if (currEvent->flags & EV_ERROR) {
        handleEventError(currEvent, kq);
      } else if (currEvent->filter == EVFILT_READ) {
        handleReadEvent(currEvent, kq);
      } else if (currEvent->filter == EVFILT_WRITE) {
        handleWriteEvent(currEvent, kq);
      } else if (currEvent->filter == EVFILT_TIMER) {
        handleRequestTimeOut(currEvent->ident, kq);
      }
    }
  }
}

void ServerOperator::handleEventError(struct kevent *event, Kqueue &kq) {
  if (_serverMap.find(event->ident) != _serverMap.end()) {
    std::cerr << "server socket error : " << event->ident << std::endl;
    close(event->ident);
    Server *newserver = new Server(_serverMap[event->ident]->getListenPort(),
                                   _serverMap[event->ident]->getSPSBList());
    delete _serverMap[event->ident];
    _serverMap.erase(event->ident);
    _serverMap[newserver->getSocket()] = newserver;
  }
  std::cerr << "client socket error : " << event->ident << std::endl;
  disconnectClient(event->ident, kq);
}

void ServerOperator::handleRequestTimeOut(int clientSock, Kqueue &kq) {
  kq.changeEvents(clientSock, EVFILT_TIMER, EV_DELETE, 0, 0, NULL);
  Response res;
  res.setErrorRes(408);
  res.sendResponse(clientSock);
  disconnectClient(clientSock, kq);
}

void ServerOperator::handleReadEvent(struct kevent *event, Kqueue &kq) {
  if (kq.getFdGroup(event->ident) == FD_SERVER) {
    int clientSocket;

    sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    if ((clientSocket = accept(event->ident, (struct sockaddr *)&clientAddr,
                               &clientAddrLen)) == -1) {
      std::cerr << "Accept() Error" << std::endl;
      return;
    }
    std::cout << "accept new client: " << clientSocket << std::endl;
    kq.setFdGroup(clientSocket, FD_CLIENT);
    std::string clientIp = ftInetNtoa(clientAddr.sin_addr);
    _clientToServer[clientSocket] = event->ident;

    fcntl(clientSocket, F_SETFL, O_NONBLOCK, FD_CLOEXEC);

    /* add event for client socket - add read && write event */
    kq.changeEvents(
        clientSocket, EVFILT_TIMER, EV_ADD | EV_ENABLE, 0,
        _serverMap[event->ident]->getSPSBList()->front()->getKeepAliveTime() *
            1000,
        NULL);
    kq.changeEvents(clientSocket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
    _clients[clientSocket] = new Request();
    _clients[clientSocket]->addHeader("ClientIP", clientIp);
  } else if (kq.getFdGroup(event->ident) == FD_CLIENT) {
    Request *req = _clients[event->ident];
    /* read data from client */
    static char buf[32768];  // reuse for every request
    int n;

    n = read(event->ident, buf, sizeof(buf));
    if (n == 0) {
      disconnectClient(event->ident, kq);
      return;
    } else if (n == -1) {
      return;
    } else {
      req->addRawContents(buf, n);
      req->parsing(_serverMap[_clientToServer[event->ident]]->getSPSBList(),
                   _locationMap);

      if (req->isFullReq()) {
        kq.changeEvents(event->ident, EVFILT_TIMER, EV_ENABLE, 0,
                        _serverMap[_clientToServer[event->ident]]
                                ->getSPSBList()
                                ->front()
                                ->getKeepAliveTime() *
                            1000,
                        NULL);
        kq.changeEvents(event->ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
        kq.changeEvents(event->ident, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0,
                        NULL);
        return;
      }
    }
  } else if (kq.getFdGroup(event->ident) == FD_CGI) {
    std::vector<int> udata = *static_cast<std::vector<int> *>(event->udata);
    int clientFd = udata[0];
    pid_t pid = udata[1];
    Request *req = _clients[clientFd];
    static char buf[32768];
    int n;

    n = read(event->ident, buf, sizeof(buf));
    if (n == -1) {
      return;
    } else {
      req->addRawContents(buf, n);
      if (waitpid(pid, NULL, WNOHANG) == pid && n == 0) {
        kq.eraseFdGroup(event->ident, FD_CGI);
        close(event->ident);
        Response *res = new Response();
        res->convertCGI(req->getRawContents());
        delete static_cast<std::vector<int> *>(event->udata);
        kq.changeEvents(clientFd, EVFILT_TIMER, EV_ENABLE, 0,
                        req->getLocBlock()->getKeepAliveTime() * 1000, res);
        kq.changeEvents(clientFd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, res);
      }
    }
  }
}

void ServerOperator::handleWriteEvent(struct kevent *event, Kqueue &kq) {
  if (kq.getFdGroup(event->ident) == FD_CGI) {
    std::vector<int> &udata = *static_cast<std::vector<int> *>(event->udata);
    int clientFd = udata[0];
    Request *req = _clients[clientFd];

    size_t bodySize = req->getBody().size();
    ssize_t bytesWritten = 0;
    int &totalBytesWritten = udata[4];
    size_t chunk = 32768;

    if (totalBytesWritten + chunk > bodySize)
      chunk = bodySize - totalBytesWritten;
    bytesWritten =
        write(event->ident,
              req->getBody().substr(totalBytesWritten, chunk).c_str(), chunk);
    if (bytesWritten == -1) {
      std::cerr << "write error" << std::endl;
      return;
    }
    totalBytesWritten += bytesWritten;

    if (totalBytesWritten == static_cast<int>(req->getBody().size())) {
      kq.eraseFdGroup(event->ident, FD_CGI);
      close(event->ident);
    }
    return;
  } else if (kq.getFdGroup(event->ident) == FD_CLIENT) {
    Request *req = _clients[event->ident];

    if (event->udata) {
      Response *res = static_cast<Response *>(event->udata);

      if (res->sendResponse(event->ident) == EXIT_FAILURE) {
        std::cerr << "client write error!" << std::endl;
        delete res;
        disconnectClient(event->ident, kq);
      }

      if (res->isFullWrite() == true) {
        delete res;
        if (req->getStatus() == 413)
          disconnectClient(event->ident, kq);
        else {
          kq.changeEvents(event->ident, EVFILT_TIMER, EV_ENABLE, 0,
                          req->getLocBlock()->getKeepAliveTime() * 1000, NULL);
          req->clear();
          kq.changeEvents(event->ident, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
          kq.changeEvents(event->ident, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0,
                          NULL);
        }
      }
      return;
    } else {
      Response *res = new Response();
      ServerBlock *locBlock = req->getLocBlock();

      if (req->getStatus() != 200) {
        res->setErrorRes(req->getStatus());
      } else {
        Method *method;
        const std::string &limit = locBlock->getLimitExcept();

        if ((req->getMethod() == "GET" || req->getMethod() == "HEAD") &&
            (limit == "GET" || limit == ""))
          method = new Get();
        else if ((req->getMethod() == "POST" || req->getMethod() == "PUT") &&
                 (limit == "POST" || limit == "")) {
          method = new Post(kq, event->ident);
        } else if (req->getMethod() == "DELETE" &&
                   (limit == "DELETE" || limit == ""))
          method = new Delete();
        else {
          method = new Method();
        }
        method->process(*req, *res);
        delete method;
      }

      if (res->isInHeader("Content-Length") == false &&
          req->getMethod() != "DELETE") {
        kq.changeEvents(event->ident, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
        delete res;
        return;
      }
      kq.changeEvents(event->ident, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
      kq.changeEvents(event->ident, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0,
                      res);
    }
  }
}

bool ServerOperator::isExistClient(int clientSock) {
  if (_clients.find(clientSock) == _clients.end()) return false;
  return true;
}

void ServerOperator::disconnectClient(int clientSock, Kqueue &kq) {
  std::cout << "client disconnected: " << clientSock << std::endl;
  kq.eraseFdGroup(clientSock, FD_CLIENT);
  close(clientSock);
  delete _clients[clientSock];
  _clients.erase(clientSock);
  _clientToServer.erase(clientSock);
}
