# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 16:01:25 by myko              #+#    #+#              #
#    Updated: 2022/07/06 16:33:09 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
DIR = ./
SRCS = ${wildcard *.c} 
OBJS = ${SRCS:.c=.o}

all : ${TARGET}

%.o : %.c
	${CC} ${CFLAGS} -c $< -I ${DIR} -o ${<:.c=.o}

${TARGET} : ${OBJS}
	ar cr ${TARGET} ${OBJS}

clean :
	rm -f ${OBJS}

fclean :
	rm -f ${OBJS} ${TARGET}

re : fclean all

.PHONY : all clean fclean re
