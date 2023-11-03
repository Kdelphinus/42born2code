#include "RPN.hpp"

int main(int ac, char *av[]) {
  if (ac != 2) {
	std::cout << "Usage: ./RPN [Polish mathematical expression]" << std::endl;
	return 1;
  }

  try {
	RPN rpn;
	std::cout << rpn.solution(av[1]) << std::endl;
  }
  catch (std::exception &e) {
	std::cout << "Error" << std::endl;
	return 1;
  }
  return 0;
}