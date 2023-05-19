#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "========ADDRESS========" << std::endl;
	std::cout << "str address: " << &str << std::endl;
	std::cout << "stringPTR: " << &stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << std::endl << "========VALUE========" << std::endl;
	std::cout << "str value: " << str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	std::cout << std::endl << "========CHANGE VALUE========" << std::endl;
	str = "BYE BYE";
	std::cout << std::endl << "========VALUE========" << std::endl;
	std::cout << "str value: " << str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}
