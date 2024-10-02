#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

  Bureaucrat(); // name을 다시 바꿀 수 없는 것은 옳지 않다고 생각하여 옮김
 public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  ~Bureaucrat();

  void incrementGrade();
  void decrementGrade();
  void signForm(Form &form);

  const std::string &getName() const;
  int getGrade() const;

  class GradeTooHighException : public std::exception {
   public:
	const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
	const char *what() const throw();
  };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
