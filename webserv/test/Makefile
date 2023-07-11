# epoll test
epoll: epoll.o
	gcc $< -o $@

epoll.o: epoll.c
	gcc -c $< -o $@

# kqueue1 test
kqueue1: kqueue1.o
	cc $< -o $@

kqueue1.o: kqueue.c
	cc -c $< -o $@

# kqueue2 test
kqueue2: kqueue2.o
	c++ $< -o $@

kqueue2.o: kqueue.cpp
	c++ -c $< -o $@

# clean, fclean
clean:
	rm -rf epoll.o kqueue1.o kqueue2.o

fclean: clean
	rm -rf epoll kqueue1 kqueue2
