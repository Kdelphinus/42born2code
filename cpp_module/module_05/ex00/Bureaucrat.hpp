#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		void upGrade();
		void downGrade();
		const std::string getName() const;
		int getGrade() const;

	class GradeTooHighException : public std::exception {
		public:
			const char *what(void) const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			const char *what(void) const throw();
	};
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
