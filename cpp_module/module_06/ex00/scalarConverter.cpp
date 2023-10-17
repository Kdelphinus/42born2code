#include "scalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::InvalidInput::what() const throw() {
	return "Error: Invalid input";
}

void ScalarConverter::isInvalidInput(const std::string &input) {
//	if (input == "+inf" || input == "-inf" || input == "inf" || input == "nan") {
//		_char = "impossible";impossible
//		_int = "impossible";
//		_float = input;
//		_double = input;
//		isPseudoLiteral = true;
//		return;
//	}
//	if (input == "+inff" || input == "-inff" || input == "inff" || input == "nanf") {
//		_char = "impossibleble";
//		_int = "impossible";
//		_float = input.substr(0, input.size() - 1);
//		_double = input.substr(0, input.size() - 1);
//		isPseudoLiteral = true;
//		return;
//	}

	if (input.find_first_of("0123456789") == input.npos)
		throw InvalidInput();
	if (input.find('+', 1) != input.npos
			|| input.find('-', 1) != input.npos)
		throw InvalidInput();
	if (input.find('f') != input.npos
			&& input.find('f') != input.size() - 1)
		throw InvalidInput();
	_isPseudoLiteral = true;
}

void ScalarConverter::convert(const std::string &input) {
	isInvalidInput(input);
	if (_isPseudoLiteral)
		return print();
}

void ScalarConverter::print() {
	std::cout << "hi" << std::endl;
//	std::cout << "char: " << _char << std::endl;
//	std::cout << "int: " << _int << std::endl;
//	std::cout << "float: " << std::fixed << _float << "f" << std::endl;
//	std::cout << "double: " << std::fixed << _double << std::endl;
}