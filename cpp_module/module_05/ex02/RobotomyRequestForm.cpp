#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm",
												  72,
												  45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
	: Form(form) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
  Form::operator=(form);
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (!isSigned())
	throw (FormNotSignedException());
  if (executor.getGrade() > getGradeToExecute())
	throw (BureaucratExecuteException());
  std::cout << "* drilling noises *" << std::endl;
  std::srand(std::time(0));
  if (std::rand() % 2)
	std::cout << getName() << " has been robotomized successfully" << std::endl;
  else
	std::cout << getName() << " robotomization failed" << std::endl;
}