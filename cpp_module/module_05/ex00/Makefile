# **************************************************************************** #
# ProgramName && Files                                                         #
# **************************************************************************** #
NAME = ex00
INC_FILES = Bureaucrat.hpp
SRC_FILES = main.cpp Bureaucrat.cpp
# **************************************************************************** #
# Directories && Paths                                                         #
# **************************************************************************** #
INC_DIR = ./
SRC_DIR = ./
OBJ_DIR = ./obj/
DEP_DIR = ./dep/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
DEPS = $(addprefix $(DEP_DIR), $(SRC_FILES:.cpp=.d))
# **************************************************************************** #
# Compiler && flags                                                            #
# **************************************************************************** #
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
INCFLAGS = -I $(INC_DIR)
DEPFLAGS = -MMD -MF $(DEP_DIR)$(@F:.o=.d)
STD_FLAG = -std=c++98
# **************************************************************************** #
# Output controls                                                              #
# **************************************************************************** #
RST =	\033[0m
GRN =	\033[1;32m
CYN =	\033[1;36m
BCY =	\033[1;96m
HOM =	\033[A
CLR =	\033[K
# **************************************************************************** #
# Rules                                                                        #
# **************************************************************************** #
.DEFAULT_GOAL = all
-include $(DEPS)
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(CXXFLAGS) $(STD_FLAG) -o $(NAME)
	@echo "$(CLR)$(GRN)$(NAME) compiled!$(RST)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@$(CXX) $(DEPFLAGS) $(INCFLAGS) $(CXXFLAGS) $(STD_FLAG) -c $< -o $@
	@echo "$(CLR)$(GRN)$(NAME) compiling... $(BCY)$<$(RST)$(HOM)"

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "$(GRN)$(NAME) cleaned!$(RST)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(HOM)$(GRN)$(NAME) fcleaned!$(RST)"

re:
	@make fclean
	@make all
	@echo "$(HOM)$(GRN)$(NAME) remade!$(RST)"

.PHONY: all clean fclean re