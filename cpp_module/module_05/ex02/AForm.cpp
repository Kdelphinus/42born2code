#include "AForm.hpp"

AForm::AForm() :
	_name("default"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150) {
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
	throw (GradeTooHighException());
  if (_gradeToSign > 150 || _gradeToExecute > 150)
	throw (GradeTooLowException());
}

AForm::AForm(const AForm &AForm) : _name(AForm.getName()),
								   _signed(AForm.isSigned()),
								   _gradeToSign(AForm.getGradeToSign()),
								   _gradeToExecute(AForm.getGradeToExecute()) {}

AForm &AForm::operator=(const AForm &AForm) {
  if (this != &AForm)
	_signed = AForm.isSigned();
  return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
  return _name;
}

bool AForm::isSigned() const {
  return _signed;
}

int AForm::getGradeToSign() const {
  return _gradeToSign;
}

int AForm::getGradeToExecute() const {
  return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
	throw (GradeTooLowException());
  _signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "the grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "the grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << "AForm: " << AForm.getName() << ", signed: " << AForm.isSigned()
	 << ", grade to sign: " << AForm.getGradeToSign()
	 << ", grade to execute: " << AForm.getGradeToExecute();
  return os;
}