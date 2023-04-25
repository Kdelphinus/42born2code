NAME = megaphone
CC = c++
CFLAG = -Wall -Wextra -Werror
STD_FLAG = -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAG) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAG) -c $(SRC) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re