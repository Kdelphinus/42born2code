#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		int idx;
		Contact contact_list[8];
	public:
		PhoneBook();
		void Add();
		void Search();
		void Exit();
};

#endif