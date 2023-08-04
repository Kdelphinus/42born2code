#include "Bureaucrat.hpp"

int main() {
	Bureaucrat wrong = Bureaucrat("wrong", 0);
	Bureaucrat test1 = Bureaucrat("test1", 1);
	Bureaucrat test2 = Bureaucrat("test2", 150);

	std::cout << "====wrong====" << std::endl;
	std::cout << "Name: " << wrong.getName() << std::endl;
	std::cout << "Grade: " << wrong.getGrade() << std::endl;
	wrong.upGrade();
	std::cout << "after up grade, Grade: " << wrong.getGrade() << std::endl;
	wrong.downGrade();
	std::cout << "after down grade, Grade: " << wrong.getGrade() << std::endl;

	std::cout << std::endl;

	std::cout << "====test1====" << std::endl;
	std::cout << "Name: " << test1.getName() << std::endl;
	std::cout << "Grade: " << test1.getGrade() << std::endl;
	test1.upGrade();
	std::cout << "after up grade, Grade: " << test1.getGrade() << std::endl;
	test1.downGrade();
	std::cout << "after down grade, Grade: " << test1.getGrade() << std::endl;

	std::cout << std::endl;

	std::cout << "====test2====" << std::endl;
	std::cout << "Name: " << test2.getName() << std::endl;
	std::cout << "Grade: " << test2.getGrade() << std::endl;
	test2.downGrade();
	std::cout << "after up grade, Grade: " << test2.getGrade() << std::endl;
	test2.upGrade();
	std::cout << "after down grade, Grade: " << test2.getGrade() << std::endl;

    return 0;
}