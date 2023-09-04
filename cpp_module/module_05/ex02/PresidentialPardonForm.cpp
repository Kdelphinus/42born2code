#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(
	"PresidentialPardonForm",) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
	: AForm(form) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
