#include "Server.hpp"

static void exitWithPerror(const std::string &msg) {
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}

Server::Server(int domain, int type, int protocol) : _serverSocket(socket(domain, type, protocol)) {
	if (_serverSocket == -1)
		exitWithPerror("socket() error\n" + std::string(strerror(errno)));
	memset(&_serverAddr, 0, sizeof(_serverAddr));
}

void Server::initServer(sa_family_t sinFamily, uint16_t sinPort, uint32_t sAddr) {
	_serverAddr.sin_family = sinFamily;
	_serverAddr.sin_port = htons(sinPort);
	_serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
}

void Server::serverBind() {
	if (bind(_serverSocket, (struct sockaddr *)&_serverAddr, sizeof(_serverAddr)) == -1)
		exitWithPerror("bind() error\n" + std::string(strerror(errno)));
}

void Server::serverListen(int num) {
	if (listen(_serverSocket, num) == -1)
		exitWithPerror("listen() error\n" + std::string(strerror(errno)));

}

void Server::serverFcntl(int fd, int cmd, int option) {
	fcntl(fd, cmd, option);
}

const int Server::getServerSocket() const {
	return _serverSocket;
}

const int Server::clientAccept(struct sockaddr *addr, socklen_t *addrLen) {
	int clientSocket;

	if ((clientSocket = accept(_serverSocket, addr, addrLen)) == -1)
		exitWithPerror("accept() error\n" + std::string(strerror(errno)));
	return clientSocket;
}