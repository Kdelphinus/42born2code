# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 14:05:24 by myko              #+#    #+#              #
#    Updated: 2023/01/04 12:33:04 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAG = -Wall -Wextra -Werror
LIBFT_FLAG = -Llib -lft

SRC_DIR = ./src/
SRC_NAME = main.c \
		   ft_atoi_int.c \
		   order.c \
		   stack_init.c \
		   quick_sort.c \
		   find_order.c \
		   sort_utils.c \
		   hard_sort_func.c \
		   utils.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = ./include/
LIBFT_DIR = ./lib/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJ) $(LIBFT_FLAG) $(FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -I $(INC) -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
