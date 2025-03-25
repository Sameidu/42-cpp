#pragma once

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <iterator>
#include <exception>
#include <sstream>
#include <ctime>

template <typename T, template <typename, typename> class C>
class PmergeMe {
	private:
		int _size;
		int _odd;
		clock_t _start;
		C<std::pair<T, T>, std::allocator<std::pair<T, T> > > _data;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(char **av, int ac);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void sort(char c);
		PmergeMe<T, C> merge(const PmergeMe<T, C> &first, const PmergeMe<T, C> &second);
    	PmergeMe<T, C> sortedPairs(const C<std::pair<T, T>, std::allocator<std::pair<T, T> > > &data);
		void insertion(C<T, std::allocator<T> > &sorted, T value);
};

#include "PmergeMe.tpp"

#endif