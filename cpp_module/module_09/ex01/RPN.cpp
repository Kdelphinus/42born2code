#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn) {
  _eq = rpn._eq;
}

RPN &RPN::operator=(const RPN &rpn) {
  if (this == &rpn)
	_eq = rpn._eq;
  return *this;
}

RPN::~RPN() {}

void RPN::stackClear() {
  while (!_eq.empty())
	_eq.pop();
}

void RPN::calculate(char op) {
  int a, b;

  a = _eq.top();
  _eq.pop();
  b = _eq.top();
  _eq.pop();

  if (op == '+')
	_eq.push(b + a);
  else if (op == '-')
	_eq.push(b - a);
  else if (op == '*')
	_eq.push(b * a);
  else if (op == '/')
	_eq.push(b / a);
}

int RPN::solution(const char *eq) {
  stackClear();
  std::string eq_str(eq);

  for (size_t i = 0; i < eq_str.length(); i++) {
	if (eq_str[i] == ' ')
	  continue;
	else if (eq_str[i] >= '0' && eq_str[i] <= '9')
	  _eq.push(eq_str[i] - '0');
	else if (eq_str[i] == '+' || eq_str[i] == '-' || eq_str[i] == '*'
		|| eq_str[i] == '/') {
	  if (_eq.size() < 2)
		throw std::exception();
	  calculate(eq_str[i]);
	} else
	  throw std::exception();
  }
  return _eq.top();
}