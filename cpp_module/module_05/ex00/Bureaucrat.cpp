#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

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

const int Bureaucrat::getGrade() const {
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