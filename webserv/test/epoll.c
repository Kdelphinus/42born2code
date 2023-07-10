#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <string.h>
#include <stdio.h>

#define EPOLL_SIZE 20
#define MAXLINE 1024

struct udata {
    int fd;
    char name[80];
};

int user_fds[1024];

void send_msg(struct epoll_event ev, char *msg);

int main(int argc, char **argv) {
    struct sockaddr_in addr, clientaddr;
    struct epoll_event ev, *events;
    struct udata *user_data;

    int listenfd;
    int clientfd;
    int i;
    socklen_t addrlen, clilen;
    int readn;
    int eventn;
    int epollfd;
    char buf[MAXLINE];

    if (argc != 2) {
        printf("Usage: %s <%s> \n ", argv[0], argv[1]);
        exit(EXIT_FAILURE);
    }

    // events 포인터를 초기화한다. EPOLL_SIZE = 20
    events = (struct epoll_event *) malloc(sizeof(struct epoll_event) * EPOLL_SIZE);
    // epoll fd를 만든다.
    if ((epollfd = epoll_create(100)) == -1)
        return -1;

    addrlen = sizeof(addr);
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return -1;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr *) &addr, addrlen) == -1) {
        perror("error : failed bind()");
        return -1;
    }

    if (listen(listenfd, 5) == -1) {
        perror("error : failed listen()");
        return -1;
    }

    // EPOLL_CTL_ADD를 통해 listen 소켓을 이벤트 풀에 추가
    ev.events = EPOLLIN; // 이멘트가 들어오면 알려줌
    ev.data.fd = listenfd; // 듣기 소켓 추가
    epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev); // listenfd의 상태변화를 epollfd를 통해 관찰
    memset(user_fds, -1, sizeof(int) * 1024);

    // 사건 발생까지 무한 대기
    // epollfd의 사건 발생 시, events에 fd를 채운다.
    // eventn은 listen에 성공한 fd의 수
    while (1) {
        eventn = epoll_wait(epollfd, events, EPOLL_SIZE, -1);
        if (eventn == -1)
            return -1;

        for (i = 0; i < eventn; i++) {
            if (events[i].data.fd == listenfd) { // 듣기 소켓에서 이벤트가 발생
                memset(buf, 0x00, MAXLINE);
                clilen = sizeof(struct sockaddr);
                clientfd = accept(listenfd, (struct sockaddr *) &clientaddr, &clilen);
                user_fds[clientfd] = 1; // 연결 처리

                user_data = malloc(sizeof(user_data));
                user_data->fd = clientfd;

                char *tmp = "First insert your nickname :";
                write(user_data->fd, tmp, strlen(tmp));

                sleep(1);
                read(user_data->fd, user_data->name, 80);
                user_data->name[strlen(user_data->name) - 1] = 0;

                printf("Welcome \"%s\"\n", user_data->name);

                sleep(1);
                sprintf(buf, "Okay your nickname %s\n", user_data->name);

                write(user_data->fd, buf, strlen(buf));

                ev.events = EPOLLIN;
                ev.data.ptr = user_data;

                epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &ev);
            } else { // 연결 소켓에서 이벤트가 발생
                user_data = events[i].data.ptr;
                memset(buf, 0x00, MAXLINE);
                readn = read(user_data->fd, buf, MAXLINE);
                if (readn <= 0) { // 읽는 도중 에러 발생
                    epoll_ctl(epollfd, EPOLL_CTL_DEL, user_data->fd, events);
                    close(user_data->fd);
                    user_fds[user_data->fd] = -1;
                    free(user_data);
                } else // 데이터를 읽는다.
                    send_msg(events[i], buf);
            }
        }
    }
}

// client가 보낸 메세지를 다른 client들에게 전송한다.
void send_msg(struct epoll_event ev, char *msg) {
    int i;
    char buf[MAXLINE + 24];
    struct udata *user_data;
    user_data = ev.data.ptr;
    for (i = 0; i < 1024; i++) {
        memset(buf, 0x00, MAXLINE + 24);
        sprintf(buf, "%s : %s", user_data->name, msg);
        if (user_fds[i] == 1)
            write(i, buf, strlen(buf));
    }
}