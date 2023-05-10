NAME = PhoneBook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g
STD_FLAG = -std=c++98

SRC = PhoneBook.cpp Contact.cpp main.cpp
INC = ./
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(CFLAG) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -I $(INC) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
