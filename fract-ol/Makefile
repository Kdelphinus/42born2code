# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 16:07:52 by myko              #+#    #+#              #
#    Updated: 2022/10/04 20:06:05 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TODO Makefile 리링크 방지하기

NAME = fractol
FLAG = -Wall -Wextra -Werror -g
MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_FLAG_LINUX = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

SRCS_DIR = ./srcs/
SRCS_NAME = main.c \
			mandelbrot_set.c \
			julia_set.c \
			multibrot_set.c \
			mandelbox.c \
			multicron.c \
			burning_ship.c \
			utils_1.c \
			utils_2.c \
			color.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_DIR_LINUX = ./objs_linux/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_LINUX = $(addprefix $(OBJS_DIR_LINUX), $(OBJS_NAME))
INC = ./includes/
MLX_LINUX_DIR = ./mlx_linux/

BOLD := $(shell tput bold)
SGR0 := $(shell tput sgr0)

all: $(OBJS)
	$(CC) $(OBJS) $(FLAG) $(MLX_FLAG) -o $(NAME)
	@printf "$(BOLD)All done!$(SGR0)\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAG) -I$(INC) -Imlx -c $< -o $@

linux: $(OBJS_LINUX)
	make -C $(MLX_LINUX_DIR)
	gcc $(FLAG) $(OBJS_LINUX) $(MLX_FLAG_LINUX) -o $(NAME)
	@printf "$(BOLD)All done!$(SGR0)\n"

$(OBJS_DIR_LINUX)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR_LINUX)
	gcc $(FLAG) -I$(INC) -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

clean_linux:
	make -C $(MLX_LINUX_DIR) clean
	rm -rf $(OBJS_DIR_LINUX)

fclean: clean
	rm -rf $(NAME)

fclean_linux: clean_linux
	rm -rf $(NAME)

re:
	make fclean
	make all

re_linux:
	make fclean_linux
	make linux

.PHONY: all linux clean clean_linux fclean fclean_linux re re_linux
