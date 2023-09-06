#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm",
													  145,
													  137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
	: Form(form) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
  Form::operator=(form);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!isSigned())
	throw (FormNotSignedException());
  if (executor.getGrade() > getGradeToExecute())
	throw (BureaucratExecuteException());
  std::ofstream file(getName() + "_shrubbery");
  if (!file.is_open())
	throw (std::runtime_error("Cannot open file"));

  file << "\n\n   			 ,@@@@@@@,\n"
  << "   	 ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
  << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
  << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
  << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
  << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
  << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
  << "   	  |o|        | |         | |\n"
  << "   	  |.|        | |         | |\n"
  << "   jgs \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
  file.close();
}
