#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
	Bureaucrat bureaucrat = Bureaucrat("bureaucrat", 42);
	Form form = Form("form", 42, 42);
	Form form2 = Form("form2", 1, 1);

	std::cout << bureaucrat;
	std::cout << form;

	std::cout << "\nsign form" << std::endl;
	bureaucrat.signForm(form);

	std::cout << "\nsign form2" << std::endl;
	bureaucrat.signForm(form2);
  } catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
  }

  return 0;
}