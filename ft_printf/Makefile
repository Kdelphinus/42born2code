# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:30:00 by myko              #+#    #+#              #
#    Updated: 2022/08/10 21:09:40 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS_DIR = ./srcs/
SRCS_NAME = ft_printf.c \
			 ft_printf_utils.c \
			 ft_printf_utils_2.c \
			 ft_printf_write.c \
			 ft_printf_write_2.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
INC = ./includes/
LIBFT_DIR = ./lib/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.a $(NAME)
	ar crs $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -I $(INC) -o $@

clean: 
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
