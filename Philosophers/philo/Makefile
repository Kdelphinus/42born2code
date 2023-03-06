# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 18:47:55 by myko              #+#    #+#              #
#    Updated: 2023/03/03 18:32:51 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAG = -Wall -Wextra -Werror -fsanitize=thread -g

SRC_DIR = ./src/
SRC_NAME = main.c \
		   check_arg.c \
		   philo_init.c \
		   philo_act.c \
		   philo_eat.c \
		   philo_sleep.c \
		   philo_print.c \
		   philo_think.c \
		   get_time.c \
		   ft_error.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC = ./inc/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -I $(INC) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
