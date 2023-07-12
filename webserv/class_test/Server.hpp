#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fcntl.h>

class Server {
	private:
		int _serverSocket;
		struct sockaddr_in _serverAddr;
    public:
//        Server();
//        Server(const Server &sv);
//        Server &operator=(const Server &sv);
//        ~Server();
		Server(int domain, int type, int protocol);

		void initServer(sa_family_t sinFamily, uint16_t sinPort, uint32_t sAddr);
		void serverBind();
		void serverListen(int num);
		void serverFcntl(int fd, int cmd, int option);

		const int getServerSocket() const;
		const int clientAccept(struct sockaddr *addr, socklen_t *addrLen);
};

#endif
