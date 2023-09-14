#include "scalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &sc)
: _input(sc.getInput()), _charInput(sc.getCharInput()), _intInput() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

std::string &ScalarConverter::getInput() const { return _input; }

char &ScalarConverter::getCharInput() const { return _charInput; }

int &ScalarConverter::getIntInput() const { return _intInput; }

float &ScalarConverter::getFloatInput() const { return _floatInput; }

double &ScalarConverter::getDoubleInput() const { return _doubleInput;}

void ScalarConverter::convert(const std::string &input) {

}

void ScalarConverter::print() const {

}