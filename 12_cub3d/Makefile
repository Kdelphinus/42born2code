NAME = cub3D

CC = cc

CFLAG = -Wall -Wextra -Werror

MLXFLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

INC = -I./includes/

LIB_FLAG = -Llib -lft

GNL_FLAG = -Lgnl -lgnl

SRC =	main.c \
		execute/raycast.c \
		execute/rendering.c \
		execute/key_press.c \
		parsing/parsing.c \
		parsing/init_info.c \
		parsing/init_mapping.c \
		parsing/check.c \
		parsing/check_dir.c \
		parsing/check_fc.c \
		parsing/read_map.c \
		utiles/error.c \
		utiles/free.c

SRC_DIR = ./srcs/

OBJS = $(SRCS:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC))

all : $(NAME)

.c.o:
	@$(CC) $(CFLAG) $(INC) $(R_INC) -c $< -o $@

$(NAME): $(OBJS) ./includes/cub3d.h
	@make -C lib
	@make -C mlx
	@make -C gnl
	@$(CC) $(MLXFLAG) $(OBJS) $(LIB_FLAG) $(GNL_FLAG) $(R_FLAG) -o $@
	@printf	"Ready for Cub3d\n"

clean :
	@make clean -C lib
	@make clean -C mlx
	@make clean -C gnl
	@$(RM) $(OBJS)
	@printf	"Run to Clean\n"

fclean : clean
	@make fclean -C lib
	@make fclean -C gnl
	@$(RM) $(NAME)
	@printf	"Run to fClean\n"

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
