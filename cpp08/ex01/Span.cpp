#include "Span.hpp"

Span::Span() : _N(0) {}

Span::~Span() {}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(Span const &other) { *this = other; }

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		_N = other._N;
		_v = other._v;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_v.size() >= _N)
		throw std::logic_error("Cannot add more numbers");
	_v.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_v.size() + std::distance(begin, end) > _N)
		throw std::logic_error("Cannot add more numbers");
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan() {
	if (_v.size() <= 1)
		throw std::logic_error("Cannot calculate span with less than 2 numbers");
	std::vector<int> cpy = _v;
	std::sort(cpy.begin(), cpy.end());
	int min = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = cpy.begin(); it != cpy.end() - 1; it++) {
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return min;
}

int Span::longestSpan() {
	if (_v.size() <= 1)
		throw std::logic_error("Cannot calculate span with less than 2 numbers");
	int min = *std::min_element(_v.begin(), _v.end());
	int max = *std::max_element(_v.begin(), _v.end());
	return max - min;
}