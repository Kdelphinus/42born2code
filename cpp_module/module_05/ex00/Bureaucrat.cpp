#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
  if (grade < 1)
	throw (GradeTooHighException());
  if (grade > 150)
	throw (GradeTooLowException());
  _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
	: _name(bureaucrat.getName()), _grade(bureaucrat.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
  _grade = bureaucrat.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
  if (_grade == 1)
	throw (GradeTooHighException());
  --_grade;
}

void Bureaucrat::decrementGrade() {
  if (_grade == 150)
	throw (GradeTooLowException());
  ++_grade;
}

const std::string &Bureaucrat::getName() const {
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
  return out << bureaucrat.getName() << ", bureaucrat grade "
			 << bureaucrat.getGrade() << "." << std::endl;
}