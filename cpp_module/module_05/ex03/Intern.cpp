#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
  *this = intern;
}

Intern &Intern::operator=(const Intern &intern) {
  if (this != &intern)
	*this = intern;
  return *this;
}

Intern::~Intern() {}

Form *Intern::makeForm(const std::string &formName, const std::string &target) {
  int key = -1;
  std::string formNames[3] =
	  {"presidential pardon", "robotomy request", "shrubbery creation"};
  for (int i = 0; i < 3; i++) {
	if (formNames[i] == formName) {
	  key = i;
	  break;
	}
  }

  if (key != -1) {
	std::cout << "Intern creates " << formName << std::endl;
	switch (key) {
	  case 0: return new PresidentialPardonForm(target);
	  case 1: return new RobotomyRequestForm(target);
	  case 2: return new ShrubberyCreationForm(target);
	  default: throw Intern::FormNotFoundException();
	}
  }
  throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}
