#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _idx(0), _totalIdx(0) {}

bool PhoneBook::_getLine(std::string& str) {
	getline(std::cin, str);
	if (std::cin.eof())
		exit(0);
	if (str.length() == 0) {
		std::cout << "No empty fields." << std::endl;
		return false;
	}
	return true;
}

void PhoneBook::add() {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	std::cout << "Input the first name: ";
	if (!this->_getLine(firstName))
		return;
	std::cout << "Input the last name: ";
	if (!this->_getLine(lastName))
		return ;
	std::cout << "Input the nickname: ";
	if (!this->_getLine(nickname))
		return ;
	std::cout << "Input the phone number: ";
	if (!this->_getLine(phoneNumber))
		return ;
	std::cout << "Input the darkest secret: ";
	if (!this->_getLine(darkestSecret))
		return ;
    if (this->_idx == 8)
		this->_idx = 0;
	_contactList[this->_idx] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	++this->_idx;
    if (this->_totalIdx < 8)
        ++this->_totalIdx;
}

bool PhoneBook::_tryAtoi(const char *line, int& result)
{
	int number;

	number = 0;
	if (*line == '\0')
		return false;
	while (*line != '\0')
	{
		if (*line >= '0' && *line <= '9')
			number = number * 10 + (*line - '0');
		else
			return false;
		++line;
	}
	result = number;
	return true;
}

void PhoneBook::search() {
	if (this->_totalIdx == 0)
	{
		std::cout << "No information." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "INDEX" << "|"
			  << std::setw(10) << "FIRST NAME" << "|"
			  << std::setw(10) << "LAST NAME" << "|"
			  << std::setw(10) << "NICKNAME" << "|" << std::endl;
	for (int i = 0; i < this->_totalIdx; ++i)
		this->_contactList[i].printInfo(i);

	int num;
	std::string i;
	std::cout << "Input index: ";
	getline(std::cin, i);
	if (std::cin.eof())
		exit(0);
	if (i.length() != 1 || !_tryAtoi(i.c_str(), num)) {
		std::cout << "Invalid index." << std::endl;
		return;
	}
	if (num < this->_totalIdx)
		this->_contactList[num].detailInfo(num);
	else
		std::cout << "Invalid index." << std::endl;
}

void PhoneBook::exitPhoneBook() {
	std::cout << "PhoneBook close." << std::endl;
	exit(0);
}