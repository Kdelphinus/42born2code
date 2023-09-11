 #include "scalarConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
	std::cout << "Usage: ./convert [input]" << std::endl;
	return 1;
  }
  ScalarConverter sc(av[1]);
  std::cout << sc << std::endl;
  return 0;
}