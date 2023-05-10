#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx(0) {}

void PhoneBook::Add() {
	if (this->idx == 7)
		this->idx = 0;
	contact_list[this->idx].Add();
	++this->idx;
}

void PhoneBook::Search() {
	while (true) {
		std::cout << std::setw(10) << "index" << "|"
				  << std::setw(10) << "first name" << "|"
				  << std::setw(10) << "last name" << "|"
				  << std::setw(10) << "nickname" << "|" << std::endl;
		for (int i = 0; i < this->idx; ++i)
			this->contact_list[i].PrintInfo(i);

		int num;
		std::cin >> num;
		if (num < this->idx) {
			this->contact_list[num].DetailInfo(num);
			break ;
		}
		else
			std::cout << "Wrong Index." << std::endl;
	}
}

void PhoneBook::Exit() {
	std::cout << "PhoneBook Close" << std::endl;
	exit(0);
}