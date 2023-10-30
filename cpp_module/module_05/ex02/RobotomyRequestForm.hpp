#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public Form {
 public:
  explicit RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &executor) const;
};

#endif
