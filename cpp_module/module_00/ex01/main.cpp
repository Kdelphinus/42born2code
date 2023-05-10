#include "PhoneBook.hpp"

int main()
{
	std::string cmd;
	PhoneBook phoneBook = PhoneBook();

	while (true) {
		std::cout << "Input command(ADD, SEARCH, EXIT): ";
		getline(std::cin, cmd);
		if (std::cin.eof())
			exit(0);
		if (cmd == "ADD")
			phoneBook.add();
		else if (cmd == "SEARCH")
			phoneBook.search();
		else if (cmd == "EXIT")
			phoneBook.exitPhoneBook();
		else
			std::cout << "Wrong command" << std::endl;
	}
}