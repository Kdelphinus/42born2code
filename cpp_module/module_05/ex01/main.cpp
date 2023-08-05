#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
	Bureaucrat bureaucrat = Bureaucrat("bureaucrat", 42);
	Form form = Form("form", 42, 42);

	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
  } catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
  }

  return 0;
}