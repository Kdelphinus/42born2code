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
  _vector = pmg._vector;
  _list = pmg._list;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmg) {
  if (this != &pmg) {
	_vector.clear();
	_list.clear();
	_vector = pmg._vector;
	_list = pmg._list;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printList() const {
  for (listConstIt it = _list.begin(); it != _list.end();
	   it++)
	std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::printVector() const {
  for (vectorConstIt it = _vector.begin();
	   it != _vector.end(); it++)
	std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::listMergeInsertion() {
  
}
