#include "Contact.hpp"

Contact::Contact() {}

void Contact::Add() {
	std::cout << "Input the first name: ";
	getline(std::cin, this->first_name);
	if (std::cin.eof())
		exit(0);
	std::cout << "Input the last name: ";
	getline(std::cin, this->last_name);
	if (std::cin.eof())
		exit(0);
	std::cout << "Input the nickname: ";
	getline(std::cin, this->nickname);
	if (std::cin.eof())
		exit(0);
	std::cout << "Input the phone number: ";
	getline(std::cin, this->phone_number);
	if (std::cin.eof())
		exit(0);
	std::cout << "Input the darkest secret: ";
	getline(std::cin, this->darkest_secret);
	if (std::cin.eof())
		exit(0);
}

void Contact::PrintInfo(int idx) {
	std::cout << std::setw(10) << idx << "|"
			  << std::setw(10) << this->first_name << "|"
			  << std::setw(10) << this->last_name << "|"
			  << std::setw(10) << this->nickname << "|" << std::endl;
}

void Contact::DetailInfo(int idx) {
	std::cout << "index: " << idx << std::endl;
	std::cout << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "phone number: " << this->phone_number << std::endl;
	std::cout << "darkest secret: " << this->darkest_secret << std::endl;
}