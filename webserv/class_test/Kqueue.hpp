#ifndef KQUEUE_HPP
#define KQUEUE_HPP

#include <sys/event.h>

#inlcude <sys/time.h>

#include <unistd.h>
#include <iostream>
#include <map>
#include <vector>
#include "utils.cpp"

class Kqueue {
	private:
		int _kq;
		map<int, std::string> _clients;
		vector<struct kevent> _changeList;
		struct kevent _eventList[8];
	public:
		Kqueue();
//        Kqueue(const Kqueue &kq);
//        Kqueue &operator=(const Kqueue &kq);
//        ~Kqueue();

		void changeEvents(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void *udata);
		void disconnectClient(int clientFd);
		int pendingEvents(int nevents, const struct timespec timeover);

		const int getKq() const;

		struct kevent *getEvent(int i) const;

		const std::string getClients(int key) const;
		void setClients(int key, std::string value, int option);

		bool getClientsEnd(struct kevent *currEvent) const;
};

#endif
