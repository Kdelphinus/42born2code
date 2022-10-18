# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 22:09:55 by myko              #+#    #+#              #
#    Updated: 2022/10/18 14:07:29 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INC = ./includes/
SRCS_DIR = ./srcs/
SRCS_NAME =  \
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
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

BONUS_NAME = \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c
BONUSES = $(addprefix $(SRCS_DIR), $(BONUS_NAME))

OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

BONUS_OBJS_NAME = $(BONUS_NAME:.c=.o)
BONUS_OBJS = $(addprefix $(OBJS_DIR), $(BONUS_OBJS_NAME))

ifdef WITH_BONUS
	OBJS_FILES = $(OBJS) $(BONUS_OBJS)
else
	OBJS_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS_FILES)
	ar crs $@ $^

bonus:
	make WITH_BONUS=1 all

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -I $(INC) -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
