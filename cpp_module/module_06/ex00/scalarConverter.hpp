#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

enum TYPE {
  CHAR,
  INT,
  FLOAT,
  DOUBLE
};

class ScalarConverter {
 private:
  static char _char;
  static int _int;
  static float _float;
  static double _double;

  static bool _isImpossible;
  static bool _isCharImpossible;
  static bool _isIntImpossible;

  ScalarConverter();
  ScalarConverter(const ScalarConverter &);
  ScalarConverter &operator=(const ScalarConverter &);
  ~ScalarConverter();

  static bool isPseudoLiteral(const std::string &input);
  static TYPE getType(const std::string &input);
  static bool isNumeric(const std::string &input);

  static void convertChar(const std::string &input);
  static bool isOverflow(const std::string &input);
  static void convertInt(const std::string &input);
  static void convertFloat(const std::string &input);
  static void convertDouble(const std::string &input);
  static void print(int precision);

 public:
  static void convert(const std::string &input);

  class InvalidInput : public std::exception {
   public:
	const char *what() const throw();
  };
};

#endif
