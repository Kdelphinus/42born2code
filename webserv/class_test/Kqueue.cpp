#include "Kqueue.hpp"

// TODO 나중에 하나로 몰기
static void exitWithPerror(const std::string &msg) {
	std::cerr << msg << std::endl;
	exit(EXIT_FAILURE);
}

Kqueue::Kqueue() : _kq(kqueue()) {
	if (_kq == -1)
		exitWithPerror("kqueue() error\n" + std::string(strerror(errno)));
}

void Kqueue::changeEvents(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void *udata) {
	struct kevent tmpEvent;

	EV_SET(&tmpEvent, ident, filter, flags, fflags, data, udata);
	_changeList.push_back(tmpEvent);
}

void Kqueue::disconnectClient(int clientFd) {
	std::cout << "client disconnected: " << clientFd << std::endl;
	close(clientFd);
	_clients.erase(clientFd);
}

int Kqueue::pendingEvents(int nevents, const struct timespec *timeout) {
	int newEvents;

	newEvents = kevent(_kq, &_changeList[0], _changeList.size(), _eventList, nevents, timeout);
	if (newEvents == -1)
		exitWithPerror("kevent() error\n" + std::string(strerror(errno)));
	_changeList.clear();
	return newEvents;
}

const int Kqueue::getKq() const {
	return _kq;
}

struct kevent *Kqueue::getEvent(int i) {
	return &_eventList[i];
}

std::string Kqueue::getClients(int key) const {
	return _clients.at(key);
}

void Kqueue::setClients(int key, std::string value, int option) {
	if (option == 0)
		_clients[key] = value;
	else if (option == 1)
		_clients[key] += value;
	else if (option == 2)
		_clients[key].clear();
}

bool Kqueue::getClientsEnd(struct kevent *currEvent) const {
	return _clients.find(currEvent->ident) != _clients.end();
}
