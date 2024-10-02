#include "../includes/Kqueue.hpp"

Kqueue::Kqueue() {
  _checkList = new std::vector<struct kevent>;
  FD_ZERO(&_fdServer);
  FD_ZERO(&_fdClient);
  FD_ZERO(&_fdCGI);
}

Kqueue::~Kqueue() {}

int Kqueue::init(ServerMap serverMap) {
  if ((_kq = kqueue()) == -1) {
    std::cout << "kqueue() error\n";
    return EXIT_FAILURE;
  }
  for (ServerMap::iterator it = serverMap.begin(); it != serverMap.end();
       it++) {
    changeEvents((*it).first, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
    FD_SET((*it).first, &_fdServer);
  }
  return EXIT_SUCCESS;
}

void Kqueue::changeEvents(uintptr_t ident, int16_t filter, uint16_t flags,
                          uint32_t fflags, intptr_t data, void *udata) {
  struct kevent tmp;

  EV_SET(&tmp, ident, filter, flags, fflags, data, udata);
  _checkList->push_back(tmp);
}

int Kqueue::countEvents() {
  int cnt;
  cnt = kevent(_kq, &(*_checkList)[0], _checkList->size(), _eventList,
               MAX_EVENTS, NULL);
  if (cnt == -1) {
    std::cout << "kevent() error\n";
    return -1;
  }
  return cnt;
}

void Kqueue::clearCheckList() { _checkList->clear(); }

struct kevent *Kqueue::getEventList() { return _eventList; }

void Kqueue::setFdGroup(int fd, e_fdGroup fdGroup) {
  switch (fdGroup) {
    case FD_SERVER:
      FD_SET(fd, &_fdServer);
      break;
    case FD_CLIENT:
      FD_SET(fd, &_fdClient);
      break;
    case FD_CGI:
      FD_SET(fd, &_fdCGI);
      break;
    default:
      break;
  }
}

void Kqueue::eraseFdGroup(int fd, e_fdGroup fdGroup) {
  switch (fdGroup) {
    case FD_SERVER:
      FD_CLR(fd, &_fdServer);
      break;
    case FD_CLIENT:
      FD_CLR(fd, &_fdClient);
      break;
    case FD_CGI:
      FD_CLR(fd, &_fdCGI);
      break;
    default:
      break;
  }
}

e_fdGroup Kqueue::getFdGroup(int fd) {
  if (FD_ISSET(fd, &_fdServer)) {
    return (FD_SERVER);
  } else if (FD_ISSET(fd, &_fdClient)) {
    return (FD_CLIENT);
  } else if (FD_ISSET(fd, &_fdCGI)) {
    return (FD_CGI);
  } else
    return (FD_NONE);
}
