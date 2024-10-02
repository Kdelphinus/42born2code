#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template<typename T>
const T &min(T &a, T &b) {
  return a < b ? a : b;
}

template<typename T>
const T &max(T &a, T &b) {
  return a > b ? a : b;
}

#endif
