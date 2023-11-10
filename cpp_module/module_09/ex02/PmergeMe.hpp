#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <limits>
#include <list>
#include <vector>

class PmergeMe {
 private:
  std::list<int> _list;
  std::vector<int> _vector;
  PmergeMe();

 public:
  PmergeMe(int ac, char *av[]);
  PmergeMe(const PmergeMe &pmg);
  PmergeMe &operator=(const PmergeMe &pmg);
  ~PmergeMe();

  void printList() const;

  class InvalidInputException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Error";
	}
  };
};

#endif
