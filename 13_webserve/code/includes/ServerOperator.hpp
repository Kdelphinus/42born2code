#ifndef SERVEROPERATOR_HPP
#define SERVEROPERATOR_HPP
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/event.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <list>

#include "Delete.hpp"
#include "Get.hpp"
#include "IMethod.hpp"
#include "Kqueue.hpp"
#include "Post.hpp"
#include "Request.hpp"
#include "Server.hpp"
#include "Utils.hpp"

class ServerOperator {
 private:
  ServerMap &_serverMap;  // key: server socket, value: Server class
  LocationMap &_locationMap;
  std::map<int, Request *> _clients;  // key: client socket, value: Request
  std::map<int, int>
      _clientToServer;  // key: client socket, value: server socket
  bool isExistClient(int clientSock);
  ServerBlock *getLocationBlock(Request &req, ServerBlock *sb);
  ServerBlock *findLocationBlock(struct kevent *event);
  // void setKeepAlive(int &fd, Server *server); //TCP 연결 관리
  void handleEventError(struct kevent *event, Kqueue &kq);
  void handleReadEvent(struct kevent *event, Kqueue &kq);
  void handleWriteEvent(struct kevent *event, Kqueue &kq);
  void handleRequestTimeOut(int clientSock, Kqueue &kq);
  void disconnectClient(int clientSock, Kqueue &kq);

 public:
  ServerOperator(ServerMap &serverMap, LocationMap &locationMap);
  ~ServerOperator();

  void run();
};

#endif
