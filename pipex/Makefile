# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 13:45:22 by myko              #+#    #+#              #
#    Updated: 2022/10/26 18:13:12 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
FLAG = -Wall -Wextra -Werror
FTPRINTF_FLAG = -Lftprintf -lftprintf

SRC_DIR = ./src/
SRC_NAME = main.c \
			error.c \
			pipe_pid.c \
			utils.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = ./include/
FTPRINTF_DIR = ./ftprintf/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(FTPRINTF_DIR)
	$(CC) $(OBJ) $(FTPRINTF_FLAG) $(FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -I $(INC) -o $@

clean:
	make -C $(FTPRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(FTPRINTF_DIR) fclean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re