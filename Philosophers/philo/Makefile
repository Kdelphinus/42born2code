# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 18:47:55 by myko              #+#    #+#              #
#    Updated: 2023/02/22 19:50:18 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAG = -Wall -Wextra -Werror

SRC_DIR = ./src/
SRC_NAME = main.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
# INC = ./inc/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
# $(CC) $(FLAG) -c $< -I $(INC) -o $@
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re