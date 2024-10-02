#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
 private:
  const std::string _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;
  std::string _target;

 public:
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(const Form &form);
  Form &operator=(const Form &form);
  virtual ~Form();

  void setSigned(bool signedValue);
  void setTarget(const std::string &target);

  const std::string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  const std::string &getTarget() const;

  void beSigned(Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
	const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
	const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
   public:
	const char *what() const throw();
  };
  class BureaucratExecuteException : public std::exception {
   public:
	const char *what() const throw();
  };
};
std::ostream &operator<<(std::ostream &os, const Form &AForm);

#endif
