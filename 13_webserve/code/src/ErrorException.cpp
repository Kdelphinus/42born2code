#include "../includes/ErrorException.hpp"

ErrorException::ErrorException(int error) : _error(error) {}

int ErrorException::getErrorCode() const throw() { return _error; }
