#include "Form.hpp"

Form::Form() :
	_name("default"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150) {}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw() {
  return "The grade is too high!";
}