#include "scalarConverter.hpp"

char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return *this;
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::InvalidInput::what() const throw() {
  return "Error: Invalid input";
}

bool ScalarConverter::isPseudoLiteral(const std::string &input) {
  if (input == "+inf" || input == "-inf" || input == "inf" ||
	  input == "+nan" || input == "-nan" || input == "nan" ||
	  input == "+inff" || input == "-inff" || input == "inff" ||
	  input == "+nanf" || input == "-nanf" || input == "nanf") {
	_double = std::atof(input.c_str());
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: " << static_cast<float>(_double) << "f\n"
			  << "double: " << _double << std::endl;
	return true;
  }
  return false;
}

bool ScalarConverter::isNumeric(const std::string &input) {
  int dotCnt = 0;
  int numCnt = 0;

  for (size_t i = 0; i < input.size(); ++i) {
	if (i == 0 && (input[i] == '-' || input[i] == '+'))
	  continue;
	if (input[i] == '.') {
	  if (dotCnt == 1)
		return false;
	  ++dotCnt;
	  continue;
	}
	if (!std::isdigit(input[i]) && input[i] != 'f')
	  return false;
	if (input[i] == 'f' && i != input.size() - 1)
	  return false;
	++numCnt;
  }
  if (numCnt == 0)
	return false;
  return true;
}

void ScalarConverter::convert(const std::string &input) {
  // inf, nan일 경우
  if (isPseudoLiteral(input))
	return;

  // 숫자가 아닌 경우
  if (!isNumeric(input))
	throw InvalidInput();

  // 소수점 처리
  int precision = 1;
  if (input.find_first_of(".") != input.npos && input[input.size() - 1] != '.')
	precision = input.size() - input.find_first_of(".") - 1;
  if (input[input.size() - 1] == 'f')
	--precision;

  print(input, precision);
}

void ScalarConverter::print(const std::string &input, int precision) {
  _double = std::atof(input.c_str());

  if (_double < 0 || _double > 127)
	std::cout << "char: impossible" << std::endl;
  else {
	_char = static_cast<char>(_double);
	if (32 < _char && _char < 127)
	  std::cout << "char: '" << _char << "'" << std::endl;
	else
	  std::cout << "char: Non displayable" << std::endl;
  }

  if (_double < static_cast<double>(std::numeric_limits<int>::min()) ||
	  _double > static_cast<double>(std::numeric_limits<int>::max()))
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
