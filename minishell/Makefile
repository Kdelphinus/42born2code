NAME = minishell

CC = cc

CFLAG = -Wall -Wextra -Werror

INC = -I./includes/

R_FLAG =  -lreadline #-L${HOME}/.brew/opt/readline/lib

#R_INC = -I${HOME}/.brew/opt/readline/include

LIB_FLAG = -Llib -lft
# > ${HOME} 환경변수를 이용해서 경로 부분이 자동으로 치환되게끔 하자.
# > brew로 readline을 설치한 맥이라면 어디서든 경로를 잘 찾을 수 있을 것이다.

SRC = main.c \
	  pipe_run.c \
	  pipe_pid.c \
	  pipe_utils.c \
	  pipe_error.c \
	  pipe_split_set.c

OBJ = $(SRC:.c=.o)

SRC_DIR = ./srcs/

OBJ_DIR := ./objs/

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS := $(addprefix $(OBJ_DIR), $(OBJ))

all : $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAG) $(INC) $(R_INC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C lib
	@$(CC) $(CFLAG) $(LIB_FLAG) $(R_FLAG) $^ -o $@
	@printf	"Get Ready for the Minishell\n"

clean :
	@make clean -C lib
	@rm -rf $(OBJ_DIR)
	@printf	"Run to Clean\n"

fclean :
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make fclean -C lib
	@printf	"Run to fClean\n"

re : fclean all

.PHONY : all clean fclean re
