#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int main() {
  std::cout << "<Vector>" << std::endl;
  std::vector<int> v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  v.push_back(0);
  try {
	for (int i = 0; i < 5; i++) {
	  std::vector<int>::iterator it = easyfind(v, i);
	  std::cout << "v[" << std::distance(v.begin(), it) << "] = " << *it
				<< std::endl;
	}
  } catch (std::exception &e) {
	std::cout << "Not found" << std::endl;
  }

  std::cout << "\n<List>" << std::endl;
  std::list<int> l;
  l.push_back(3);
  l.push_back(2);
  l.push_back(1);
  l.push_back(0);
  try {
	for (int i = 0; i < 5; i++) {
	  std::list<int>::iterator it = easyfind(l, i);
	  std::cout << "l[" << std::distance(l.begin(), it) << "] = " << *it
				<< std::endl;
	}
  } catch (std::exception &e) {
	std::cout << "Not found" << std::endl;
  }

  std::cout << "\nDeque" << std::endl;
  std::deque<int> d;
  d.push_back(3);
  d.push_back(2);
  d.push_back(1);
  d.push_back(0);
  try {
	for (int i = 0; i < 5; i++) {
	  std::deque<int>::iterator it = easyfind(d, i);
	  std::cout << "d[" << std::distance(d.begin(), it) << "] = " << *it
				<< std::endl;
	}
  } catch (std::exception &e) {
	std::cout << "Not found" << std::endl;
  }

  return 0;
}