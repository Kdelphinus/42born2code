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
  Span(unsigned int n) : _n(n) {};
  Span(const Span &span) : _n(span._n) {
	std::copy(span._v.begin(), span._v.end(), _v.begin());
  };
  Span &operator=(const Span &span) {
	if (this != &span) {
	  _n = span._n;
	  _v.clear();
	  std::copy(span._v.begin(), span._v.end(), _v.begin());
	}
	return *this;
  };
  ~Span() {};

  // TODO 있는 숫자를 또 삽입하려 했을 때 에러 처리
  void addNumber(int n) {
	if (_v.size() == _n)
	  throw FullException();
	_v.push_back(n);
  };
  void addNumber(int begin, int end) {
	if (end < begin || _v.size() + (end - begin) > _n)
	  throw FullException();
	for (int i = begin; i < end; i++)
	  _v.push_back(i);
  };

  int shortestSpan() {
	if (_v.size() < 2)
	  throw NotEnoughElementsException();
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end(); ++it)
	  min = std::min(min, *it - *(it - 1));
	return min;
  };
  int longestSpan() {
	if (_v.size() < 2)
	  throw NotEnoughElementsException();
	return *std::max_element(_v.begin(), _v.end())
		- *std::min_element(_v.begin(), _v.end());
  };

  class FullException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Span is full";
	}
  };
  class NotEnoughElementsException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Not enough elements";
	}
  };
};

#endif
