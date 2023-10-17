#include "scalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert [input]" << std::endl;
		return 1;
	}

	ScalarConverter::convert(av[1]);
	return 0;
}