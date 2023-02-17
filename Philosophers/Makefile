NAME = example
SRC = my_example.c
OBJ = my_example.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	gcc -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re