#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
 private:
  const std::string _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;
 public:
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(const Form &form);
  Form &operator=(const Form &form);
  ~Form();

  const std::string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
   public:
	virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
	virtual const char *what() const throw();
  };
};
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
