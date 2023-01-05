# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 21:46:03 by myko              #+#    #+#              #
#    Updated: 2023/01/05 21:47:33 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAG = -Wall -Wextra -Werror
LIBFT_FLAG = -Llib -lft

SRC_DIR = ./src/
SRC_NAME = main_bonus.c \
		   order_bonus.c \
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
