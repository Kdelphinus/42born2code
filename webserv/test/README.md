## epoll test

```shell
# 서버
make epolll
./epoll <port_number>
```

```shell
# 클라이언트
telnet 127.0.0.1 <port_number>
```

여러 터미널에서 클라이언트를 접속하면 클라이언트끼리 채팅하는 서버가 만들어진다.

## kqueue test

```shell
make kqueue
./kqueue
```

예제 코드는 [이 곳](https://hyeonski.tistory.com/9)에 있는 것이다.