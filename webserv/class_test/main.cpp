#include "Kqueue.hpp"
#include "Server.hpp"
#include "utils.c"

int main() {
	Server ser = Server(PF_INET, SOCK_STREAM, 0);

	ser.initServer(AF_INET, htons(8080), htonl(INADDR_ANY));
	ser.bind();
	ser.listen(5);
	ser.fcntl(ser.getServerSocket(), F_SETFL, O_NONBLOCK);

	Kqueue kq = Kqueue();
	kq.changeEvents(ser.getServerSocket(), EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	std::cout << "echo server started" << std::endl;

	int newEvents;
	struct kevent *currEvent;
	while (1) {
		newEvents = kq.pendingEvents(8, NULL);

		for (int i = 0; i < newEvents; ++i) {
			currEvent = kq.getEvent(i);

			if (currEvent->flags & EV_ERROR) {
				if (currEvent->ident == ser.getServerSocket())
					exitWithPerror("server socket error");
				else {
					std::cerr << "client socket error" << std::endl;
					kq.disconnectClient(currEvent->ident);
				}
			}
			else if (currEvent->filter == EVFILT_READ) {
				if (currEvent->ident == ser.getServerSocket()) {
					int clientSocket = ser.accept(NULL, NULL);
					std::cout << "accept new client: " << clientSocket << std::endl;
					ser.fcntl(clientSocket, F_SETFL, O_NONBLOCK);

					kq.changeEvents(clientSocket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
					kq.changeEvents(clientSocket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
					kq.setClients(clientSocket, "", 0);
				}
				else if (kq.getClientsEnd(currEvent)) {
					char buf[1024];
					int n = read(currEvent->ident, buf, sizeof(buf));

					if (n <= 0) {
						if (n < 0)
							std::cerr << "client read error!" << std::endl;
						kq.disconnectClient(currEvent->ident);
					}
					else {
						buf[n] = '\0';
						kq.setClients(currEvent->ident, buf, 1);
						std::cout << "received data from " << currEvent->ident << ": " << kq.getClients(currEvent->ident) << std::endl;
					}
				}
			}
			else if (currEvent->filter == EVFILT_WRITE) {
				if (kq.getClientsEnd(currEvent)) {
					if (kq.getClients(currEvent->ident) != "") {
						int n;
						if ((n = write(currEvent->ident, kq.getClients(currEvent->ident).c_str(), kq.getClients(currEvent->ident).size()) == -1)) {
							std::cerr << "client write error!" << std::endl;
							kq.disconnectClient(currEvent->ident);
						}
						else
							kq.setClients(currEvent->ident, "", 2);
					}
				}
			}
		}
	}
}
