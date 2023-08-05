#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
    public:
        Form();
        Form(const Form &form);
        Form &operator=(const Form &form);
        ~Form();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
