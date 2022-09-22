# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 16:07:52 by myko              #+#    #+#              #
#    Updated: 2022/09/22 19:23:54 by myko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS_DIR = ./srcs/
SRCS_NAME = main.c \
	mandelbrot_set.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
INC = ./includes/
MLX_LINUX_DIR = ./mlx_linux

all:
	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

ubuntu: $(OBJS)
	make -C $(MLX_LINUX_DIR)
	gcc $(OBJS) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	gcc -I$(INC) -Imlx_linux -O3 -c $< -o $@

clean:
	make -C $(MLX_LINUX_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all ubuntu clean fclean re