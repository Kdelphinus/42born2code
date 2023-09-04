#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &form);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
  ~ShrubberyCreationForm();
};

#endif
