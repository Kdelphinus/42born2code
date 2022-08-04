# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:30:00 by myko              #+#    #+#              #
#    Updated: 2022/08/04 15:57:34 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a

LIBFT = -L ./lib/libft -lft

all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -I . $(LIBFT) -o $(NAME)

libft:
	make -C ./lib/libft all

clean: 
	make -C ./lib/libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C ./lib/libft fclean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all libft clean fclean re
