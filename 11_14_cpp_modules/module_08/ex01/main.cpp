#include "Span.hpp"

int main() {
  try {
    {
      Span sp = Span(10000);
      sp.addNumber(0, 10000);

      std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
      std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    {
      Span sp = Span(10000);
      std::vector<int> test;
      for (int i = 0; i < 10000; i++)
        test.push_back(i);
      sp.addNumber(test.begin(), test.end());

      std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
      std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}