#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
  try {
  	Bureaucrat bureaucrat = Bureaucrat("bureaucrat", 5);
	ShrubberyCreationForm shrubberyCreationForm = ShrubberyCreationForm();
	RobotomyRequestForm robotomyRequestForm = RobotomyRequestForm();
	PresidentialPardonForm presidentialPardonForm = PresidentialPardonForm();

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