GCC = gcc
GCC_FLAGS = -Wall -Wextra -Werror

epoll:
	$(GCC) $(GCC_FLAGS) epoll.c -o epoll

kqueue:
	$(GCC) $(GCC_FLAGS) kqueue.c -o kqueue

clean:
	rm -rf epoll kqueue

re:
	make clean
	make all
