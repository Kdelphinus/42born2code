#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter {
 private:
  static char _char;
  static int _int;
  static float _float;
  static double _double;

  ScalarConverter();
  ScalarConverter(const ScalarConverter &);
  ScalarConverter &operator=(const ScalarConverter &);
  ~ScalarConverter();

  static bool isPseudoLiteral(const std::string &input);
  static bool isNumeric(const std::string &input);
  static void print(const std::string &input, int precision);

 public:
  static void convert(const std::string &input);

  class InvalidInput : public std::exception {
   public:
	const char *what() const throw();
  };
};

#endif
