#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
 private:
  unsigned int _n;
  std::vector<int> _v;
  Span();

 public:
  Span(unsigned int n);
  Span(const Span &span);
  Span &operator=(const Span &span);
  ~Span();

  void addNumber(int n);
  void addNumber(int begin, int end);
  template<typename T>
  void addNumber(T begin, T end) {
    if (end < begin)
      throw std::runtime_error("Error: invalid input");
    if (_v.size() + (end - begin) > _n)
      throw std::runtime_error("Span is full");
    for (T it = begin; it != end; ++it) {
      _v.push_back(*it);
    }
  }

  int shortestSpan();
  int longestSpan();
};

#endif
