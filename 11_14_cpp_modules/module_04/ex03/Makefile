NAME = interfaceAndRecap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g
STD_FLAG = -std=c++98

SRC = main.cpp \
	  AMateria.cpp \
	  Cure.cpp \
	  Ice.cpp \
	  Character.cpp \
	  MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(STD_FLAG) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(STD_FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re