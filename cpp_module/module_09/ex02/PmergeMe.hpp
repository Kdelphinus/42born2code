#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe &pmg);
  PmergeMe &operator=(const PmergeMe &pmg);
  ~PmergeMe();
};

#endif
