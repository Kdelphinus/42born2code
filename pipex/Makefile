# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 13:45:22 by myko              #+#    #+#              #
#    Updated: 2022/12/06 17:17:22 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAG = -Wall -Wextra -Werror
LIBFT_FLAG = -Llib -lft

ifdef WITH_BONUS
	SRC_DIR = ./src_bonus/
	SRC_NAME = main_bonus.c \
			error_bonus.c \
			pipe_pid_bonus.c \
			utils_bonus.c \
			ft_split_set_bonus.c
	OBJ_DIR = ./obj_bonus/
else
	SRC_DIR = ./src/
	SRC_NAME = main.c \
			error.c \
			pipe_pid.c \
			utils.c \
			ft_split_set.c
	OBJ_DIR = ./obj/
endif

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = ./include/
LIBFT_DIR = ./lib/

all: $(NAME)

bonus:
	make WITH_BONUS=1 all

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJ) $(LIBFT_FLAG) $(FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -I $(INC) -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf ./obj/ ./obj_bonus/

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus