#pragma once

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <exception>
#include <sstream>

class PmergeMe {
	private:
		std::vector<int> _v;
		std::deque<int> _d;
		std::list<int> _l;
		PmergeMe();

	public:
		~PmergeMe();
		PmergeMe(char **av, int ac);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void merge();
};

#endif