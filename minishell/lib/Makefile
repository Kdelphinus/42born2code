# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 16:38:01 by juyojeon          #+#    #+#              #
#    Updated: 2023/03/30 13:11:47 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putwchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c ft_isspace.c ft_ismetachar.c \

OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BOUNS = $(SRCS_BONUS:.c=.o)
INC = .

all : $(NAME)

bonus : $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS) $(OBJS_BOUNS)
	@ar -rcs $@ $(OBJS) $(OBJS_BOUNS)
else
$(NAME): $(OBJS)
	@ar -rcs $@ $(OBJS)
endif

%.o : %.c
	@cc -c $(CFLAGS) $< -o $@ -I $(INC)

clean :
	@rm -f $(OBJS) $(OBJS_BOUNS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re