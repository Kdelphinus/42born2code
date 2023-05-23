#ifndef SED_H
#define SED_H

#include <iostream>
#include <fstream>

enum error {
	ARG,
	OPEN,
};

// main.cpp
void my_error(int num);

// sed.cpp
std::string my_sed(std::string origin, std::string s1, std::string s2);

#endif
