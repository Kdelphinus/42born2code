#include "Form.hpp"

Form::Form() :
		_name(),
		_signed(false),
		_limitSignGrade(150),
		_limitExecuteGrade(150) {}

Form::Form(std::string name, int limitSignGrade, int limitExecuteGrade) : _name(name), _signed(false) {
	try {
		if (limitSignGrade < 1)
			throw (GradeTooHighException());
		if (limitSignGrade > 150)
			throw (GradeTooLowException());
		if (limitExecuteGrade < 1)
			throw (GradeTooHighException());
		if (limitExecuteGrade > 150)
			throw (GradeTooLowException());
	} catch (GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form &form) :
		_name(form.getName()),
		_signed(form.getSigned()),
		_limitSignGrade(form.getLimitSignGrade()),
		_limitExecuteGrade(form.getLimitExecuteGrade()) {}

Form &Form::operator=(const Form &form) {
	_name = form.getName();
	_signed = form.getSigned();
	_limitSignGrade = form.getLimitSignGrade();
	_limitExecuteGrade = form.getLimitExecuteGrade();
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getLimitSignGrade() const {
	return _limitSignGrade;
}

int Form::getLimitExecuteGrade() const {
	return _limitExecuteGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	try {
		if (bureaucrat.getGrade() > _limitSignGrade)
			throw (GradeTooLowException());
		_signed = true;
	} catch (GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return "The grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "The grade is too low!";
}
