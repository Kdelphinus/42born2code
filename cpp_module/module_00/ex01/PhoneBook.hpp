#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		int _idx;
        int _totalIdx;
		Contact _contactList[8];
		bool _tryAtoi(const char *line, int& result);
		bool _getLine(std::string& str);
	public:
		PhoneBook();
		void add();
		void search();
		void exitPhoneBook();
};

#endif