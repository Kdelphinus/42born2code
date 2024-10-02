#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int n) {
  typename T::iterator it = std::find(container.begin(), container.end(), n);
  if (it == container.end())
	throw std::exception();
  return it;
}

#endif
