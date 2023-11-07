#include "Span.hpp"

int main() {
  try {
	Span sp = Span(10000);

	sp.addNumber(0, 10000);

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
	std::cout << e.what() << std::endl;
  }

  return 0;
}