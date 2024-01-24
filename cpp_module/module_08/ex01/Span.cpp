#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &span) : _n(span._n) {
    std::copy(span._v.begin(), span._v.end(), _v.begin());
}

Span &Span::operator=(const Span &span) {
    if (this != &span) {
        _n = span._n;
        _v.clear();
        std::copy(span._v.begin(), span._v.end(), _v.begin());
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_v.size() == _n)
        throw std::runtime_error("Span is full");
    _v.push_back(n);
}

void Span::addNumber(int begin, int end) {
    if (end < begin || _v.size() + (end - begin) > _n)
        throw std::runtime_error("Span is full");
    for (int i = begin; i < end; i++) {
        _v.push_back(i);
    }
}

int Span::shortestSpan() {
    if (_v.size() < 2)
        throw std::runtime_error("Not enough elements");;
    std::vector<int> tmp(_v);
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end(); ++it)
        min = std::min(min, *it - *(it - 1));
    return min;
}

int Span::longestSpan() {
    if (_v.size() < 2)
        throw std::runtime_error("Not enough elements");;
    return *std::max_element(_v.begin(), _v.end())
           - *std::min_element(_v.begin(), _v.end());
}
