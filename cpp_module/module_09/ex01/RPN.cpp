#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn) : _eq(rpn._eq) {}

RPN &RPN::operator=(const RPN &rpn) {
  if (this != rpn)
	_eq = rpn._eq;
  return *this;
}

RPN::~RPN() {}
