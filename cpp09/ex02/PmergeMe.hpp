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
		int _size;
		PmergeMe();

	public:
		~PmergeMe();
		PmergeMe(char **av, int ac);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void merge();

		template <typename T> void fordJohnson(T &container, clock_t &time);
		template <typename T> void printMessage(T &container, char c);		
};

#endif