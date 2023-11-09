#include "iter.hpp"

template<typename T>
void print(T &x) {
  std::cout << x << " ";
}

int main() {
  char tab_char[] = {'a', 'b', 'c', 'd', 'e'};
  int tab[] = {0, 1, 2, 3, 4};
  double tab_double[] = {0.0, 1.1, 2.2, 3.3, 4.4};

  std::cout << "iter(tab_char, 5, print<const char>): ";
  iter(tab_char, 5, print<const char>);
  std::cout << std::endl;

  std::cout << "iter(tab_char, 5, print<char>): ";
  iter(tab_char, 5, print<char>);
  std::cout << std::endl;

  std::cout << "iter(tab, 5, print<const int>): ";
  iter(tab, 5, print<const int>);
  std::cout << std::endl;

  std::cout << "iter(tab, 5, print<int>): ";
  iter(tab, 5, print<int>);
  std::cout << std::endl;

  std::cout << "iter(tab_double, 5, print<const double>): ";
  iter(tab_double, 5, print<const double>);
  std::cout << std::endl;

  std::cout << "iter(tab_double, 5, print<double>): ";
  iter(tab_double, 5, print<double>);
  std::cout << std::endl;
  return 0;
}