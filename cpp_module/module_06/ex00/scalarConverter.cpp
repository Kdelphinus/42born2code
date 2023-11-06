#include "scalarConverter.hpp"

char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;
bool ScalarConverter::_isImpossible;
bool ScalarConverter::_isCharImpossible;
bool ScalarConverter::_isIntImpossible;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return *this;
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::InvalidInput::what() const throw() {
  return "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan";
}

bool ScalarConverter::isPseudoLiteral(const std::string &input) {
  if (input == "+inf" || input == "-inf" || input == "inf" ||
	  input == "+nan" || input == "-nan" || input == "nan") {
	_double = std::atof(input.c_str());
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: " << static_cast<float>(_double) << "f\n"
			  << "double: " << _double << std::endl;
	return true;
  }
  if (input == "+inff" || input == "-inff" || input == "inff" ||
	  input == "+nanf" || input == "-nanf" || input == "nanf") {
	_float = static_cast<float>(std::atof(input.c_str()));
	std::cout << "char: impossible\n"
			  << "int: impossible\n"
			  << "float: " << _float << "\n"
			  << "double: " << static_cast<double>(_float) << std::endl;
	return true;
  }
  return false;
}

TYPE ScalarConverter::getType(const std::string &input) {
  if (input.find_first_of(".") != input.npos) {
	if (input[input.size() - 1] == 'f')
	  return FLOAT;
	return DOUBLE;
  }
  if (input.size() == 1 && !std::isdigit(input[0]))
	return CHAR;
  return INT;
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
  if (numCnt == 0 || (dotCnt == 0 && input[input.size() - 1] == 'f'))
	return false;
  return true;
}

void ScalarConverter::convertChar(const std::string &input) {
  _char = input[0];
  _int = static_cast<int>(_char);
  _float = static_cast<float>(_char);
  _double = static_cast<double>(_char);
}

bool ScalarConverter::isOverflow(const std::string &input) {
  size_t len = input.size();
  if (input[0] == '-' || input[0] == '+')
	--len;

  if (len > 10) {
	_isImpossible = true;
	return true;
  }

  if (len == 10) {
	if (input[0] == '-') {
	  if (input.compare("-2147483648") > 0) {
		_isImpossible = true;
		return true;
	  }
	} else if (input[0] == '+') {
	  if (input.compare("+2147483647") > 0) {
		_isImpossible = true;
		return true;
	  }
	} else {
	  if (input.compare("2147483647") > 0) {
		_isImpossible = true;
		return true;
	  }
	}
  }
  return false;
}

void ScalarConverter::convertInt(const std::string &input) {
  if (isOverflow(input)) {
	_isImpossible = true;
	return;
  }
  _int = std::atoi(input.c_str());

  if (_int < std::numeric_limits<char>::min() ||
	  std::numeric_limits<char>::max() < _int)
	_isCharImpossible = true;
  else
	_char = static_cast<char>(_int);

  _float = static_cast<float>(_int);
  _double = static_cast<double>(_int);
}

void ScalarConverter::convertFloat(const std::string &input) {
  _float = static_cast<float>(std::atof(input.c_str()));

  if (_float < static_cast<float>(std::numeric_limits<char>::min()) ||
	  static_cast<float>(std::numeric_limits<char>::max()) < _float)
	_isCharImpossible = true;
  else
	_char = static_cast<char>(_float);

  if (_float < static_cast<float>(std::numeric_limits<int>::min()) ||
	  static_cast<float>(std::numeric_limits<int>::max()) < _float)
	_isIntImpossible = true;
  else
	_int = static_cast<int>(_float);

  _double = static_cast<double>(_float);
}

void ScalarConverter::convertDouble(const std::string &input) {
  _double = std::atof(input.c_str());

  if (_double < std::numeric_limits<char>::min() ||
	  std::numeric_limits<char>::max() < _double)
	_isCharImpossible = true;
  else
	_char = static_cast<char>(_double);

  if (_double < static_cast<double>(std::numeric_limits<int>::min()) ||
	  static_cast<double>(std::numeric_limits<int>::max()) < _double)
	_isIntImpossible = true;
  else
	_int = static_cast<int>(_double);

  _float = static_cast<float>(_double);
}

void ScalarConverter::print(int precision) {
  if (_isCharImpossible || _isImpossible)
	std::cout << "char: impossible" << std::endl;
  else {
	if (32 < _char && _char < 127)
	  std::cout << "char: '" << _char << "'" << std::endl;
	else
	  std::cout << "char: Non displayable" << std::endl;
  }

  if (_isIntImpossible || _isImpossible)
	std::cout << "int: impossible" << std::endl;
  else
	std::cout << "int: " << _int << std::endl;

  if (_isImpossible)
	std::cout << "float: impossible" << std::endl;
  else {
	std::cout << "float: " << std::fixed << std::setprecision(precision)
			  << _float
			  << "f" << std::endl;
  }

  if (_isImpossible)
	std::cout << "double: impossible" << std::endl;
  else {
	std::cout << "double: " << std::fixed << std::setprecision(precision)
			  << _double
			  << std::endl;
  }
}

void ScalarConverter::convert(const std::string &input) {
  if (isPseudoLiteral(input))
	return;

  TYPE type = getType(input);
  if (type == CHAR) {
	convertChar(input);
  } else {
	if (!isNumeric(input))
	  throw InvalidInput();
	if (type == INT)
	  convertInt(input);
	else if (type == FLOAT)
	  convertFloat(input);
	else
	  convertDouble(input);
  }

  int precision = 1;
  if (input.find_first_of(".") != input.npos && input[input.size() - 1] != '.')
	precision = input.size() - input.find_first_of(".") - 1;
  if (input.size() > 1 && input[input.size() - 1] == 'f'
	  && input[input.size() - 2] != '.')
	--precision;

  print(precision);
}
