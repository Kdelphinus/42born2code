# **************************************************************************** #
# ProgramName && Files                                                         #
# **************************************************************************** #
NAME		=	WebServ
INC_FILES	=	Kqueue.hpp LocationBlock.hpp ConfigParser.hpp Server.hpp \
				Request.hpp Response.hpp RootBlock.hpp ServerBlock.hpp \
				ServerOperator.hpp Cgi.hpp Get.hpp Post.hpp Delete.hpp \
				IMethod.hpp Utils.hpp Method.hpp ErrorException.hpp
SRC_FILES	=	Kqueue.cpp LocationBlock.cpp ConfigParser.cpp Server.cpp \
				Request.cpp Response.cpp RootBlock.cpp ServerBlock.cpp \
				ServerOperator.cpp Cgi.cpp Get.cpp Post.cpp Delete.cpp \
				Utils.cpp Method.cpp main.cpp ErrorException.cpp
# **************************************************************************** #
# Directories && Paths                                                         #
# **************************************************************************** #
INC_DIR =	./includes/
SRC_DIR =	./src/
OBJ_DIR =	.obj/
DEP_DIR =	.dep/
SRCS	=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS	=	$(addprefix $(OBJ_DIR), $(SRC_FILES:%.cpp=%.o))
DEPS	=	$(SRC_FILES:%.cpp=$(DEP_DIR)%.d)
# **************************************************************************** #
# Compiler && flags                                                            #
# **************************************************************************** #
CXX			=	c++
# CXXFLAGS =
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
CPPFLAGS	=	-I$(INC_DIR)
DEPFLAGS	=	-MMD -MP -MF $(@:$(OBJ_DIR)%.o=$(DEP_DIR)%.d)
RM			=	rm -rf
# **************************************************************************** #
# Debug options                                                                #
# **************************************************************************** #
ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address,undefined
endif
ifdef C
	CXX = c++-7
endif
Q = @
ifdef PRINT
	Q =
endif
# **************************************************************************** #
# Output controls                                                              #
# **************************************************************************** #
NAME_LEN = $(shell echo $(NAME) | tr -d '\n' | wc -c)
ifeq ($(shell echo "$(NAME_LEN)-6" | bc | grep -c '-'), 1)
	N = 6
else
	N = $(NAME_LEN)
endif
RST =	\033[0m
GRN =	\033[1;32m
CYN =	\033[1;36m
BCY =	\033[1;96m
HOM =	\033[A
CLR =	\033[K
# **************************************************************************** #
# Rules                                                                        #
# **************************************************************************** #
.DEFAULT_GOAL	=	all
-include $(DEPS)
all				:	$(NAME)
$(NAME)			:	$(OBJS)
						@$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
						@printf "$(CLR)$(GRN)%$Ns is Ready ✅\\n$(RST)" $(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp
						@mkdir -p $(OBJ_DIR) $(DEP_DIR)
						@printf \
						"$(CLR)$(GRN)%$Ns is Ready : $<$(RST)$(HOM)\\n" $(NAME)
						@$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<
						
clean			:
						$Q$(RM) $(OBJ_DIR) $(DEP_DIR) *.dSYM
						@printf "$(CYN)%$Ns Objects! 🗑$(RST)\\n" Remove
fclean			:	clean
						$Q$(RM) $(NAME)
						@printf "$(BCY)%$Ns Program! 🗑$(RST)\\n" Remove
re				:	fclean
						 @make all
.PHONY			:	all clean fclean re
