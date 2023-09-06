#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm(std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &executor) const;
};

#endif
