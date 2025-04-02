#pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <exception>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _v;
		Span();
	
	public:
		~Span();
		Span(unsigned int n);
		Span(Span const &other);

		Span &operator=(Span const &other);
		
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif