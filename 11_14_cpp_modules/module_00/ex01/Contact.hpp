#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		std::string _checkLength(std::string str);
	public:
		Contact();
		Contact(
				std::string firstName,
				std::string lastName,
				std::string nickname,
				std::string phoneNumber,
				std::string darkestSecret
		);
		void printInfo(int idx);
		void detailInfo(int idx);
};

#endif
