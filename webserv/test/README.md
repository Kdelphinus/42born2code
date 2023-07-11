## epoll test 방법

```shell
# 서버
make all
./epoll <port_number>
```

```shell
# 클라이언트
telnet 127.0.0.1 <port_number>
```

여러 터미널에서 클라이언트를 접속하면 클라이언트끼리 채팅하는 서버가 만들어진다.
