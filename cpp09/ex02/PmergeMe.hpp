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
#include <list>
#include <iterator>
#include <exception>
#include <sstream>

template <typename T, template <typename, typename> class C>
class PmergeMe {
	private:
		int _size;
		int _odd;
		C<std::pair<T, T>, std::allocator<std::pair<T, T> > > _data;
		PmergeMe();

	public:
		//~PmergeMe();
		PmergeMe(char **av, int ac);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void sort();
		void printPair() const;
};

#include "PmergeMe.tpp"

#endif