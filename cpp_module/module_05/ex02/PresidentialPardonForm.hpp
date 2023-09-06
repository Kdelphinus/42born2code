#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &form);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
  ~PresidentialPardonForm();

  void execute(Bureaucrat const &executor) const;
};

#endif
