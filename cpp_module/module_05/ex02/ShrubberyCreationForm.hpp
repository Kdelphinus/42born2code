#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public Form {
 public:
  ShrubberyCreationForm(std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &form);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const;
};

#endif
