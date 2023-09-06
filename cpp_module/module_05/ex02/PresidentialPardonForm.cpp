#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(
	"PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
	: AForm(form) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
  AForm::operator=(form);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!isSigned())
	throw (FormNotSignedException());
  if (executor.getGrade() > getGradeToExecute())
	throw (BureaucratExecuteException());
  std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}