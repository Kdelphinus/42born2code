# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 22:09:55 by myko              #+#    #+#              #
#    Updated: 2022/07/08 11:20:31 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -c
NAME 	= libft.a

SRCS =  \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memcpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_striteri.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c


BONUSES = \
ft_lstnew.c \
ft_lstadd_front.c \
#ft_lstsize.c \
#ft_lstlast.c \
#ft_lstadd_back.c \
#ft_lstdelone.c \
#ft_lstclear.c \
#ft_lstiter.c \
#ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUSES:.c=.o)
ifdef WITH_BONUS
	OBJ_FILES = ${OBJS} ${BONUS_OBJS}
else
	OBJ_FILES = ${OBJS}
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar crs $@ $(OBJ_FILES)

bonus:
	make WITH_BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
