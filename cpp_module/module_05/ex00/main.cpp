#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat wrong = Bureaucrat("wrong", 0);

		std::cout << "====wrong====" << std::endl;
		std::cout << "Name: " << wrong.getName() << std::endl;
		std::cout << "Grade: " << wrong.getGrade() << std::endl;
		wrong.incrementGrade();
		std::cout << "after up grade, Grade: " << wrong.getGrade() << std::endl;
		wrong.decrementGrade();
		std::cout << "after down grade, Grade: " << wrong.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat test1 = Bureaucrat("test1", 1);

		std::cout << "====test1====" << std::endl;
		std::cout << "Name: " << test1.getName() << std::endl;
		std::cout << "Grade: " << test1.getGrade() << std::endl;
		test1.incrementGrade();
		std::cout << "after up grade, Grade: " << test1.getGrade() << std::endl;
		test1.decrementGrade();
		std::cout << "after down grade, Grade: " << test1.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat test2 = Bureaucrat("test2", 150);

		std::cout << "====test2====" << std::endl;
		std::cout << "Name: " << test2.getName() << std::endl;
		std::cout << "Grade: " << test2.getGrade() << std::endl;
		test2.decrementGrade();
		std::cout << "after up grade, Grade: " << test2.getGrade() << std::endl;
		test2.incrementGrade();
		std::cout << "after down grade, Grade: " << test2.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat test3 = Bureaucrat("test3", 42);

		std::cout << "====test3====" << std::endl;
		std::cout << "Name: " << test3.getName() << std::endl;
		std::cout << "Grade: " << test3.getGrade() << std::endl;
		test3.decrementGrade();
		std::cout << "after up grade, Grade: " << test3.getGrade() << std::endl;
		test3.incrementGrade();
		std::cout << "after down grade, Grade: " << test3.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}