#include <iostream>
#include <stdlib.h>

void exitWithPerror(const string &msg) {
	std::cerr << msg << endl;
	exit(EXIT_FAILURE);
}