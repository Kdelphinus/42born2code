#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
 private:
  std::stack<int> _eq;

  void stackClear();
  void calculate(char op);
 public:
  RPN();
  RPN(const RPN &rpn);
  RPN &operator=(const RPN &rpn);
  ~RPN();

  int solution(const char *eq);

  class ZeroDivisionException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Error: division by zero";
	}
  };
};

#endif
