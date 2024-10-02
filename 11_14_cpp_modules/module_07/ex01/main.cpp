#include "iter.hpp"

template<typename T>
void print(T &x) {
  std::cout << x << " ";
}

int main() {
  char tabChar[] = {'a', 'b', 'c', 'd', 'e'};
  int tab[] = {0, 1, 2, 3, 4};
  double tabDouble[] = {0.0, 1.1, 2.2, 3.3, 4.4};

  std::cout << "iter(tabChar, 5, print<const char>): ";
  iter(tabChar, 5, print<const char>);
  std::cout << std::endl;

  std::cout << "iter(tabChar, 5, print<char>): ";
  iter(tabChar, 5, print<char>);
  std::cout << std::endl;

  std::cout << "iter(tab, 5, print<const int>): ";
  iter(tab, 5, print<const int>);
  std::cout << std::endl;

  std::cout << "iter(tab, 5, print<int>): ";
  iter(tab, 5, print<int>);
  std::cout << std::endl;

  std::cout << "iter(tabDouble, 5, print<const double>): ";
  iter(tabDouble, 5, print<const double>);
  std::cout << std::endl;

  std::cout << "iter(tabDouble, 5, print<double>): ";
  iter(tabDouble, 5, print<double>);
  std::cout << std::endl;
  return 0;
}