#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  RobotomyRequestForm();
 public:
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &executor) const;
};

#endif
