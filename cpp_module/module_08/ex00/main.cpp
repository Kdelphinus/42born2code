#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

int main() {
  std::cout << "\nVector" << std::endl;
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  try {
	std::cout << *easyfind(v, 2) << std::endl;
	std::cout << *easyfind(v, 3) << std::endl;
	std::cout << *easyfind(v, 1) << std::endl;
	std::cout << *easyfind(v, 4) << std::endl;
  } catch (std::exception &e) {
	std::cout << "Not found" << std::endl;
  }

  std::cout << "\nList" << std::endl;
  std::list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  try {
	std::cout << *easyfind(l, 2) << std::endl;
	std::cout << *easyfind(l, 3) << std::endl;
	std::cout << *easyfind(l, 1) << std::endl;
	std::cout << *easyfind(l, 4) << std::endl;
  } catch (std::exception &e) {
	std::cout << "Not found" << std::endl;
  }

  std::cout << "\nDeque" << std::endl;
  std::deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  try {
	std::cout << *easyfind(d, 2) << std::endl;
	std::cout << *easyfind(d, 3) << std::endl;
	std::cout << *easyfind(d, 1) << std::endl;
	std::cout << *easyfind(d, 4) << std::endl;
  } catch (std::exception &e) {
	std::cout << "Not found" << std::endl;
  }

  std::cout << "\nSet" << std::endl;
  std::set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  try {
	std::cout << *easyfind(s, 2) << std::endl;
	std::cout << *easyfind(s, 3) << std::endl;
	std::cout << *easyfind(s, 1) << std::endl;
	std::cout << *easyfind(s, 4) << std::endl;
  }
  catch (std::exception &e) {
	std::cout << "Not found" << std::endl;
  }
  return 0;
}