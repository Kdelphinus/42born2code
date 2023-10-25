#ifndef SPAN_HPP
#define SPAN_HPP

#incldue <iostream>
#include <algorithm>

class Span {
 public:
  Span();
  Span(const Span &span);
  Span &operator=(const Span &span);
  ~Span();
};

#endif
