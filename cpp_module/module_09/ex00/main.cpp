#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
	if (ac == 1) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	} else if (ac > 2) {
		std::cout << "Error: too many arguments." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange be;
		be.printExchange(av[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}