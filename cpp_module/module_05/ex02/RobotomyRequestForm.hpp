#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &executor) const;
};

#endif
