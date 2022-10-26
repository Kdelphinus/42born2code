# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 13:45:22 by myko              #+#    #+#              #
#    Updated: 2022/10/26 13:48:36 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
FLAG = -g
FLAG = -Wall -Wextra -Werror
FTPRINTF_FLAG = -Lftprintf -lftprintf

SRCS_DIR = ./srcs/
SRCS_NAME = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
INC = ./includes/
FTPRINTF_DIR = ./ftprintf/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(FTPRINTF_DIR)
	$(CC) $(OBJS) $(FTPRINTF_FLAG) $(FLAG) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAG) -c $< -I $(INC) -o $@

clean:
	make -C $(FTPRINTF_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(FTPRINTF_DIR) fclean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re