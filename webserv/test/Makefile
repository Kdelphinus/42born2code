NAME = epoll
GCC = gcc
GCC_FLAGS = -Wall -Wextra -Werror

SRC = epoll.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(OBJ) $(GCC_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re