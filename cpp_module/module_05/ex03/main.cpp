#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
  try {
	Bureaucrat bender("Bender", 50);
	Intern someRandomIntern;
	Form *rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	bender.signForm(*rrf);
	bender.executeForm(*rrf);
	delete rrf;
  } catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
  }
  return 0;
}