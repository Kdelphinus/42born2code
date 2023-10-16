#include "scalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input(""),
																		 _charIsNonDisplayable(false),
																		 _charIsImpossible(false),
																		 _intIsImpossible(false),
																		 _floatIsImpossible(false),
																		 _doubleIsImpossible(false) {}

ScalarConverter::ScalarConverter(const std::string &input)
		: _input(input),
			_charIsNonDisplayable(false),
			_charIsImpossible(false),
			_intIsImpossible(false),
			_floatIsImpossible(false),
			_doubleIsImpossible(false) {}

ScalarConverter::ScalarConverter(const ScalarConverter &sc)
		: _input(sc._input),
			_charIsNonDisplayable(sc._charIsNonDisplayable),
			_charIsImpossible(sc._charIsImpossible),
			_intIsImpossible(sc._intIsImpossible),
			_floatIsImpossible(sc._floatIsImpossible),
			_doubleIsImpossible(sc._doubleIsImpossible) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) {
	if (this != &sc) {
		_input = sc._input;
		_charIsNonDisplayable = sc._charIsNonDisplayable;
		_charIsImpossible = sc._charIsImpossible;
		_intIsImpossible = sc._intIsImpossible;
		_floatIsImpossible = sc._floatIsImpossible;
		_doubleIsImpossible = sc._doubleIsImpossible;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

const std::string &ScalarConverter::getInput() const { return _input; }

void ScalarConverter::setInput(const std::string &input) { _input = input; }

void ScalarConverter::convert(const std::string &input) {
	double d = std::atof(input.c_str());

	// TODO nan, inf, -inf 구현해야 함
	if (d < 0 || d > 127)
		_charIsImpossible = true;
	else if (std::isprint(static_cast<int>(d)))
		_charInput = static_cast<char>(d);
	else
		_charIsNonDisplayable = true;

	if (d < INT_MIN || d > INT_MAX) {
		_intIsImpossible = true;
		_floatIsImpossible = true;
		_doubleIsImpossible = true;
	} else {
		_intInput = static_cast<int>(d);
		_floatInput = static_cast<float>(d);
		_doubleInput = static_cast<double>(d);
	}
}

void ScalarConverter::print() const {
	if (_charIsImpossible)
		std::cout << "char: impossible" << std::endl;
	else if (_charIsNonDisplayable)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _charInput << "'" << std::endl;

	if (_intIsImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _intInput << std::endl;

	if (_floatIsImpossible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << _floatInput << "f" << std::endl;

	if (_doubleIsImpossible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << _doubleInput << std::endl;
}
