#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  try {
	std::string target = "target";
	Bureaucrat bureaucrat = Bureaucrat("bureaucrat", 5);
	ShrubberyCreationForm shrubberyCreationForm = ShrubberyCreationForm(target);
	RobotomyRequestForm robotomyRequestForm = RobotomyRequestForm(target);
	PresidentialPardonForm
		presidentialPardonForm = PresidentialPardonForm(target);

	std::cout << "** ShrubberyCreationForm **" << std::endl;
	bureaucrat.signForm(shrubberyCreationForm);
	bureaucrat.executeForm(shrubberyCreationForm);

	std::cout << "\n** RobotomyRequestForm **" << std::endl;
	bureaucrat.signForm(robotomyRequestForm);
	bureaucrat.executeForm(robotomyRequestForm);

	std::cout << "\n** PresidentialPardonForm **" << std::endl;
	bureaucrat.signForm(presidentialPardonForm);
	bureaucrat.executeForm(presidentialPardonForm);
  } catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
  }
  return 0;
}