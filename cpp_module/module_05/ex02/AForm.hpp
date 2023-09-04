#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
 private:
  const std::string _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;
 public:
  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &AForm);
  AForm &operator=(const AForm &AForm);
  ~AForm();

  void setName(const std::string &name);
  void setSigned(bool sign);
  void setGradeToSign(int gradeToSign);
  void setGradeToExecute(int gradeToExecute);

  const std::string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

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
};
std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
