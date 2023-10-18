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
	if (input == "+inf" || input == "-inf" || input == "inf" || input == "nan") {
		std::cout << "char: impossible\n"
							<< "int: impossible\n"
							<< "float: " << input << "f\n"
							<< "double: " << input << std::endl;
		_isPseudoLiteral = true;
	} else if (input == "+inff" || input == "-inff" || input == "inff"
			|| input == "nanf") {
		std::cout << "char: impossible\n"
							<< "int: impossible\n"
							<< "float: " << input << "\n"
							<< "double: " << input.substr(0, input.size() - 1) << std::endl;
		_isPseudoLiteral = true;
	} else {
		if (input.find_first_of("0123456789") == input.npos)
			throw InvalidInput();
		if (input.find('+', 1) != input.npos
				|| input.find('-', 1) != input.npos)
			throw InvalidInput();
		if (input.find('f') != input.npos
				&& input.find('f') != input.size() - 1)
			throw InvalidInput();
	}
}

void ScalarConverter::convert(const std::string &input) {
	isInvalidInput(input);
	if (_isPseudoLiteral) // 의사 리터럴
		return;

	// 숫자가 없는 경우
	if (input.find_first_of("0123456789") == input.npos)
		throw (InvalidInput());

	// 부호가 부정확한 위치에 있는 경우
	if (input.substr(1, input.size()).find_first_of("+-") != input.npos)
		throw (InvalidInput());

	// f가 부정확한 위치에 있는 경우
	if (input.substr(0, input.size() - 1).find_first_of("f") != input.npos)
		throw (InvalidInput());

	// .이 여러개 있는 경우
	if (input.find_first_of(".") != input.find_last_of("."))
		throw (InvalidInput());

	print();
}

void ScalarConverter::print() {
	std::cout << "char: " << static_cast<char>(_char) << std::endl;
	std::cout << "int: " << static_cast<int>(_int) << std::endl;
	std::cout << "float: " << std::fixed << static_cast<float>(_float) << "f"
						<< std::endl;
	std::cout << "double: " << std::fixed << static_cast<double>(_double)
						<< std::endl;
}