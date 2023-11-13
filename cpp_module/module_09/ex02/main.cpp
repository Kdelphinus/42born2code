#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
  if (ac < 2) {
	std::cout << "Error" << std::endl;
	return 1;
  }

  PmergeMe pmg(ac, av);

  std::cout << "Before: ";
  pmg.printList();
  pmg.listMergeInsertion();

  return 0;
}