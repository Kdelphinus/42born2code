#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern &intern);
  Intern &operator=(const Intern &intern);
  ~Intern();

  Form *makeForm(const std::string &formName, const std::string &target);

  class FormNotFoundException : public std::exception {
   public:
	const char *what() const throw();
  };
};

#endif
