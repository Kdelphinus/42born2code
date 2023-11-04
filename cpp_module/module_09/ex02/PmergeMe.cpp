#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmg) {
  *this = pmg;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmg) {
  return *this;
}

PmergeMe::~PmergeMe() {}
