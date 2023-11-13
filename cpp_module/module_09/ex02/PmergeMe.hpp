#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <limits>
#include <list>
#include <vector>
#include <cstdlib>

typedef std::list<int>::const_iterator listConstIt;
typedef std::vector<int>::const_iterator vectorConstIt;

class PmergeMe {
 private:
  std::list<int> _list;
  std::vector<int> _vector;

  PmergeMe();
  PmergeMe(const PmergeMe &pmg);
  PmergeMe &operator=(const PmergeMe &pmg);

 public:
  PmergeMe(int ac, char *av[]);
  ~PmergeMe();

  void printList() const;
  void printVector() const;
  void listMergeInsertion();
  void vectorMergeInsertion();

  class InvalidInputException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Error";
	}
  };
};

#endif
