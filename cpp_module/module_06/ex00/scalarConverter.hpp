#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConverter {
 private:
	std::string _input;
	char _charInput;
	int _intInput;
	float _floatInput;
	double _doubleInput;

	bool _charIsNonDisplayable;
	bool _charIsImpossible;
	bool _intIsImpossible;
	bool _floatIsImpossible;
	bool _doubleIsImpossible;

 public:
	ScalarConverter(void);
	ScalarConverter(const std::string &input);
	ScalarConverter(const ScalarConverter &sc);
	ScalarConverter &operator=(const ScalarConverter &sc);
	~ScalarConverter(void);

	const std::string &getInput(void) const;
	void setInput(std::string const &input);

	void convert(const std::string &input);
	void print(void) const;
};

#endif
