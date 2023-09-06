#include "AForm.hpp"

Form::Form() :
	_name("default"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150) {
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
	throw (GradeTooHighException());
  if (_gradeToSign > 150 || _gradeToExecute > 150)
	throw (GradeTooLowException());
}

Form::Form(const Form &form) : _name(form.getName()),
							   _signed(form.isSigned()),
							   _gradeToSign(form.getGradeToSign()),
							   _gradeToExecute(form.getGradeToExecute()) {}

Form &Form::operator=(const Form &form) {
  if (this != &form)
	_signed = form.isSigned();
  return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
  return _name;
}

bool Form::isSigned() const {
  return _signed;
}

int Form::getGradeToSign() const {
  return _gradeToSign;
}

int Form::getGradeToExecute() const {
  return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
	throw (GradeTooLowException());
  _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "the grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "the grade is too low!";
}

const char *Form::FormNotSignedException::what() const throw() {
  return "the form is not signed!";
}

const char *Form::BureaucratExecuteException::what() const throw() {
  return "the bureaucrat cannot execute the form!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "AForm: " << form.getName() << ", signed: " << form.isSigned()
	 << ", grade to sign: " << form.getGradeToSign()
	 << ", grade to execute: " << form.getGradeToExecute();
  return os;
}