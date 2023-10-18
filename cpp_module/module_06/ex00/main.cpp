#include "scalarConverter.hpp"

char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;
bool ScalarConverter::_isPseudoLiteral = false;

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert [input]" << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(av[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}