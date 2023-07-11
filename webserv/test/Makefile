GCC_FLAGS = -Wall -Wextra -Werror

epoll:
	gcc $(GCC_FLAGS) epoll.c -o epoll

kqueue:
	c++ $(GCC_FLAGS) kqueue.c -o kqueue

fclean:
	rm -rf epoll kqueue
