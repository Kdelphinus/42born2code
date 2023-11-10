#include "MutantStack.hpp"
#include <list>

int main() {
  {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "mstack: ";
	while (it != ite) {
	  std::cout << *it << " ";
//	  *it = 100;  // iterator 타입은 값을 바꿀 수있다.
	  ++it;
	}
	std::cout << std::endl;

	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cend = mstack.end();
	std::cout << "const: ";
	while (cit != cend) {
	  std::cout << *cit << " ";
//	  *cit = 100;  // const_iterator 타입은 값을 바꿀 수 없다. compile error
	  ++cit;
	}
	std::cout << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rend = mstack.rend();
	std::cout << "reverse: ";
	while (rit != rend) {
	  std::cout << *rit << " ";
	  ++rit;
	}
	std::cout << std::endl;

	std::stack<int> s(mstack);
	std::cout << "stack size: " << s.size() << std::endl;
//	std::stack<int>::iterator sit = s.begin(); //  stack은 iterator가 없다.
  }

  std::cout << "\n============================================\n" << std::endl;

  {
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << "list back: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "list size: " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	std::cout << "list: ";
	while (it != ite) {
	  std::cout << *it << " ";
	  ++it;
	}
	std::cout << std::endl;
	std::list<int> s(list);
  }
  return 0;
}