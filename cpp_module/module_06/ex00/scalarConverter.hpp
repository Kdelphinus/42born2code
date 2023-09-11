#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
 private:
  std::string _input;

 public:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &sc);
  ScalarConverter &operator=(ScalarConverter const &sc);
  ~ScalarConverter(void);

  std::string &getInput(void) const;

  void convert(const std::string &input);
  void print(void) const;
};

#endif
