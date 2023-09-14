#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
 private:
	std::string _input;
	char _charInput;
	int _intInput;
	float _floatInput;
	double _doubleInput;
 public:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &sc);
	ScalarConverter &operator=(ScalarConverter const &sc);
	~ScalarConverter(void);

	std::string &getInput(void) const;
	char &getCharInput(void) const;
	int &getIntInput(void) const;
	float &getFloatInput(void) const;
	double &getDoubleInput(void) const;

	void convert(const std::string &input);
	void print(void) const;
};

#endif
