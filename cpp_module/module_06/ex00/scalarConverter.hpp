#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
 private:
	static std::string _input;
	static std::string _char;
	static std::string _int;
	static std::string _float;
	static std::string _double;

	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();

 public:
	static void convert(const std::string &input);

	class InvalidInput : public std::exception {
	 public:
		const char *what() const throw();
	};
};

#endif
