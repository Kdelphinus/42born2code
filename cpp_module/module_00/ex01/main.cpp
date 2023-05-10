#include "PhoneBook.hpp"

int main()
{
	std::string cmd;
	PhoneBook phoneBook = PhoneBook();

	while (1) {
		std::cout << "Input command(ADD, SEARCH, EXIT): ";
		getline(std::cin, cmd);
		if (std::cin.eof())
			exit(0);
		if (cmd == "ADD")
			phoneBook.Add();
		else if (cmd == "SEARCH")
			phoneBook.Search();
		else if (cmd == "EXIT")
			phoneBook.Exit();
		else
			std::cout << "Wrong command" << std::endl;
	}
}