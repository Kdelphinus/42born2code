#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
  try {
	if (ac != 2)
	  throw BitcoinExchange::FileException();

	BitcoinExchange be;
	be.printExchange(av[1]);
  }
  catch (std::exception &e) {
	std::cout << e.what() << std::endl;
	return 1;
  }
  return 0;
}