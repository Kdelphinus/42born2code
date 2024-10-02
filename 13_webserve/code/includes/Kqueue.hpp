#ifndef KQUEUE_HPP
#define KQUEUE_HPP

#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/event.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <list>
#include <map>
#include <vector>

#include "Server.hpp"

#define MAX_EVENTS 1000

typedef enum {
    FD_NONE,
    FD_SERVER,
    FD_CLIENT,
    FD_CGI,
} e_fdGroup;

class Server;
// key: server socket, value: Server class
typedef std::map<int, Server *> ServerMap;

class Kqueue {
  private:
    int _kq;
    std::vector<struct kevent> *_checkList;
    struct fd_set _fdServer;
    struct fd_set _fdClient;
    struct fd_set _fdCGI;
    struct kevent
        _eventList[MAX_EVENTS]; // kevent array for saving event infomation

  public:
    Kqueue();
    ~Kqueue();

    int init(ServerMap serverMap);
    void changeEvents(uintptr_t ident, int16_t filter, uint16_t flags,
                      uint32_t fflags, intptr_t data, void *udata);
    int countEvents();
    void clearCheckList();
    struct kevent *getEventList();
    void setFdGroup(int fd, e_fdGroup fdGroup);
    void eraseFdGroup(int fd, e_fdGroup fdGroup);
    e_fdGroup getFdGroup(int fd);
};

#endif
