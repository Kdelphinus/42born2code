#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int ac, char **av) {
    int clnt_sock;
    struct sockaddr_in serv_addr;
    char message[1024] = {0x00, };

    clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (clnt_sock == -1)
        error_handling("socket error");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(av[1]);
    serv_addr.sin_port = htons(atoi(av[2]));

    if (connect(clnt_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect error");
    if (read(clnt_sock, message, sizeof(message) - 1) == -1)
        error_handling("read error");
    printf("Message from server: %s\n", message);

    close(clnt_sock);
    return 0;
}