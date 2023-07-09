## epoll test 방법

```shell
# 서버
make epoll
./epoll <port_number>
```

```shell
# 클라이언트
telnet 127.0.0.1 <port_number>
```

클라이언트끼리 채팅하는 서버가 만들어진다.
