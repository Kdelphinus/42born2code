#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
	: AForm(form) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
