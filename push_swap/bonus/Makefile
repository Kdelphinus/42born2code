# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:55:13 by myko              #+#    #+#              #
#    Updated: 2023/01/09 19:45:30 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAG = -Wall -Wextra -Werror
LIBFT_FLAG = -L../lib -lft

SRC_DIR = ./src/
SRC_NAME = main_bonus.c \
		   stack_init_bonus.c \
		   quick_sort_bonus.c \
		   check_commands_bonus.c \
		   commands_bonus.c \
		   utils_bonus.c \
		   ft_atoi_int_bonus.c \
		   gnl_bonus.c \
		   gnl_utils_bonus.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = ./include/
LIBFT_DIR = ../lib/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR) bonus
	$(CC) $(OBJ) $(LIBFT_FLAG) $(FLAG) -o $(NAME)
	mv $(NAME) ../

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -I $(INC) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf ../$(NAME)

.PHONY: all clean fclean
