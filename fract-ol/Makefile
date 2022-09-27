# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 16:07:52 by myko              #+#    #+#              #
#    Updated: 2022/09/27 17:38:55 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAG = -Wall -Wextra -Werror

SRCS_DIR = ./srcs/
SRCS_NAME = main.c \
			mandelbrot_set.c \
			julia_set.c \
			utils_1.c \
			utils_2.c \
			color.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
INC = ./includes/
MLX_LINUX_DIR = ./mlx_linux/

BOLD := $(shell tput bold)
SGR0 := $(shell tput sgr0)

all:
	@$(CC) $(FLAG) -Lmlx -lmlx -framework OpenGL -framework AppKit -I$(INC) $(SRCS) -o $(NAME)
	@printf "$(BOLD)All done!$(SGR0)\n"

ubuntu: $(OBJS)
	@make -C $(MLX_LINUX_DIR)
	@gcc $(FLAG) $(OBJS) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@printf "$(bold)All done!$(sgr0)\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@gcc -I$(INC) -Imlx_linux -O3 -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

clean_ubuntu:
	@make -C $(MLX_LINUX_DIR) clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

fclean_ubuntu: clean_ubuntu
	@rm -rf $(NAME)

re:
	@make fclean
	@make all

.PHONY: all ubuntu clean clean_ubuntu fclean fclean_ubuntu re
