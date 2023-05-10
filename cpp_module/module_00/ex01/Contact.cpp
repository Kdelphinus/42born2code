#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

std::string Contact::_checkLength(std::string str) {
	if (str.length() > 10) {
		std::string tmp = str.substr(0, 9);
		tmp += ".";
		return (tmp);
	}
	return (str);
}

void Contact::printInfo(int idx) {
	std::cout << std::setw(10) << idx << "|"
			  << std::setw(10) << _checkLength(this->_firstName) << "|"
			  << std::setw(10) << _checkLength(this->_lastName) << "|"
			  << std::setw(10) << _checkLength(this->_nickname) << "|" << std::endl;
}

void Contact::detailInfo(int idx) {
	std::cout << "index: " << idx << std::endl;
	std::cout << "first name: " << this->_firstName << std::endl;
	std::cout << "last name: " << this->_lastName << std::endl;
	std::cout << "nickname: " << this->_nickname << std::endl;
	std::cout << "phone number: " << this->_phoneNumber << std::endl;
	std::cout << "darkest secret: " << this->_darkestSecret << std::endl;
}
