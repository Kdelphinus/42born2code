#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	try {
		if (grade < 1)
			throw (GradeTooHighException());
		if (grade > 150)
			throw (GradeTooLowException());
		_grade = grade;
	} catch (GradeTooHighException &e) {
		_grade = 150;
		std::cerr << e.what() << std::endl;
	} catch (GradeTooLowException &e) {
		_grade = 150;
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	_grade = bureaucrat.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::upGrade() {
	try {
		if (_grade == 1)
			throw (GradeTooHighException());
		--_grade;
	} catch (GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::downGrade() {
	try {
		if (_grade == 150)
			throw (GradeTooLowException());
		++_grade;
	} catch (GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
}

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	return out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
}