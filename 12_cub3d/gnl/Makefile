# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 13:13:14 by jaekkang          #+#    #+#              #
#    Updated: 2022/10/17 20:35:51 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

FLAGS = -Wall -Wextra -Werror
HEADER = get_next_line.h
SRCS = get_next_line.c
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar crs $@ $^

.c.o :
	@cc $(FLAGS) -c $< -I ${HEADER} -o ${<:.c=.o}

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
