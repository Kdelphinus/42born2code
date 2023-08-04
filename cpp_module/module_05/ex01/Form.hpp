#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _limitSignGrade;
		const int _limitExecuteGrade;
	public:
		Form();
		Form(std::string name, int limitSignGrade, int limitExecuteGrade);
		Form(const Form &form);
		Form &operator=(const Form &form);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getLimitSignGrade() const;
		int getLimitExecuteGrade() const;

		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
