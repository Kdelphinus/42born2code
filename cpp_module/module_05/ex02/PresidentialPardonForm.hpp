#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &form);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
  ~PresidentialPardonForm();
};

#endif
