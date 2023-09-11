#include "scalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &sc)
	: _input(sc.getInput()) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) {
  if (this != &sc)
	_input = sc.getInput();
  return *this;
}

ScalarConverter::~ScalarConverter() {}

std::string &ScalarConverter::getInput() const { return _input; }