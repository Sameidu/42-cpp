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

class PmergeMeVector {
	private:
		int _size;
		int _odd;
		clock_t _start;
		std::vector<std::pair<int, int> > _data;

	public:
		PmergeMeVector();
		~PmergeMeVector();
		PmergeMeVector(int ac, char **av);
		PmergeMeVector(const PmergeMeVector &other);
		PmergeMeVector &operator=(const PmergeMeVector &other);

		void sortv();
		PmergeMeVector merge(const PmergeMeVector &first, const PmergeMeVector &second);
		PmergeMeVector sortedPairs(const std::vector<std::pair<int, int> > &data);
		void insertion(std::vector<int> &sorted, int value);
};

class PmergeMeDeque {
	private:
		int _size;
		int _odd;
		clock_t _start;
		std::deque<std::pair<int, int> > _data;
		
	public:
		PmergeMeDeque();
		~PmergeMeDeque();
		PmergeMeDeque(int ac, char **av);
		PmergeMeDeque(const PmergeMeDeque &other);
		PmergeMeDeque &operator=(const PmergeMeDeque &other);

		void sortd();
		PmergeMeDeque merge(const PmergeMeDeque &first, const PmergeMeDeque &second);
		PmergeMeDeque sortedPairs(const std::deque<std::pair<int, int> > &data);
		void insertion(std::deque<int> &sorted, int value);
};

#endif