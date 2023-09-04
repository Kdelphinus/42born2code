#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",
													   145,
													   137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
	: AForm(form) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
