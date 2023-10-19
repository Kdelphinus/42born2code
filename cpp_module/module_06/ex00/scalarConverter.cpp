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
	if (input == "+inf" || input == "-inf" || input == "inf" ||
			input == "+nan" || input == "-nan" || input == "nan" ||
			input == "+inff" || input == "-inff" || input == "inff" ||
			input == "+nanf" || input == "-nanf" || input == "nanf") {
		_double = std::atof(input.c_str());
		std::cout << "char: impossible\n"
							<< "int: impossible\n"
							<< "float: " << static_cast<float>(_double) << "f\n"
							<< "double: " << _double << std::endl;
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
	if (_isPseudoLiteral)
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

	// 소수점 처리
	const char *inputChar = const_cast<char *>(input.c_str());
	int precision = 1;
	if (input.find_first_of(".") != input.npos && input[input.size() - 1] != '.')
		precision = input.size() - input.find_first_of(".") - 1;

	print(inputChar, precision);
}

void ScalarConverter::print(const char *&input, int precision) {
	_double = std::atof(input);

	if (_double < 0 || _double > 127)
		std::cout << "char: impossible" << std::endl;
	else {
		_char = static_cast<char>(_double);
		if (32 < _char && _char < 127)
			std::cout << "char: '" << _char << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	if (_double < static_cast<int>(std::numeric_limits<int>::min()) ||
			_double > static_cast<int>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else {
		_int = static_cast<int>(_double);
		std::cout << "int: " << _int << std::endl;
	}

	if (_double < -static_cast<double>(std::numeric_limits<float>::max()) ||
			_double > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: impossible" << std::endl;
	else {
		_float = static_cast<float>(_double);
		std::cout << "float: " << std::fixed << std::setprecision(precision)
							<< _float
							<< "f" << std::endl;
	}

	if (_double < -std::numeric_limits<double>::max() ||
			_double > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(precision)
							<< _double
							<< std::endl;
}
