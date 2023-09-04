#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
  try {
	Bureaucrat bureaucrat = Bureaucrat("bureaucrat", 42);
	std::cout << bureaucrat;

  } catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
  }

  return 0;
}