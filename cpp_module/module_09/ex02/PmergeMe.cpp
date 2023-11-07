#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char *av[]) {
  double d;
  double i_min = static_cast<double>(std::numeric_limits<int>::min());
  double i_max = static_cast<double>(std::numeric_limits<int>::max());

  for (int i = 1; i < ac; i++) {
	d = std::atof(av[i]);
	if (d < i_min || d > i_max || d <= 0)
	  throw InvalidInputException();
	_vector.push_back(std::atoi(av[i]));
	_list.push_back(std::atoi(av[i]));
  }
}

PmergeMe::PmergeMe(const PmergeMe &pmg) {
  *this = pmg;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmg) {
  (void)pmg;
  return *this;
}

PmergeMe::~PmergeMe() {}

