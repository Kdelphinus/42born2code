#include "../includes/Server.hpp"

Server::Server(const int port, SPSBList *sbList)
    : _socket(-1), _listenPort(port), _sbList(sbList) {
  _keepAliveTime = sbList->front()->getKeepAliveTime();
}

Server::~Server() {}

int Server::init() {
  if ((_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
    std::cout << "socket() error\n" << std::endl;
    return EXIT_FAILURE;
  }

  fcntl(_socket, F_SETFL, O_NONBLOCK, FD_CLOEXEC);

  struct sockaddr_in serverAddr;
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddr.sin_port = htons(this->_listenPort);
  std::cout << "listen port: " << this->_listenPort << std::endl;

  if (bind(_socket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
    std::cout << "bind() error\n" << std::endl;
    return EXIT_FAILURE;
  }

  if (listen(_socket, 1024) == -1) {
    std::cerr << "listen() error\n" << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int Server::getSocket() const { return _socket; }
int Server::getListenPort() const { return _listenPort; }
SPSBList *Server::getSPSBList() const { return _sbList; }
size_t Server::getkeepAliveTime() const { return _keepAliveTime; }