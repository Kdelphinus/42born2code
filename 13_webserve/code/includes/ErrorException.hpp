#ifndef ERROREXCEPTION_HPP
#define ERROREXCEPTION_HPP

#include <iostream>

class ErrorException : public std::exception {
 private:
  int _error;

 public:
  ErrorException(int error);
  int getErrorCode() const throw();
};

#endif
