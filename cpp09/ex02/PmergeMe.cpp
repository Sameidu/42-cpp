#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_v = other._v;
		_d = other._d;
		_size = other._size;
	}
	return *this;
}

PmergeMe::PmergeMe(char **av, int ac) {
	std::stringstream ss;
	for (int i = 0; i < ac; i++) {
		ss << av[i] << " ";
	}
	std::string num;
	while (ss >> num) {
		for (size_t i = 0; i < num.size(); i++) {
			if (!isdigit(num[i]) && num[i] != '-' && num[i] != '+')
				throw std::invalid_argument("Invalid character in the expression");
			if ((num[i] == '-' || num[i] == '+') && !isdigit(num[i + 1]))
				throw std::invalid_argument("Cannot have a sign without a number or two signs in a row");
		}
		int n;
		std::stringstream res(num);
		res >> n;
		if (n < 0) {
			throw std::invalid_argument("Only positive numbers are allowed");
		}
		_v.push_back(n);
		_d.push_back(n);
		// std::cout << "Vector: " << _v.back() << std::endl;
		// std::cout << "Deque: " << _d.back() << std::endl;
	}
	printMessage(_v, 'b');
	printMessage(_d, 'b');
	_size = _v.size();
}

void PmergeMe::merge() {
	clock_t v_time = clock();
	clock_t d_time = clock();

	fordJohnson(_v, v_time);
	fordJohnson(_d, d_time);

	printMessage(_v, 'a');
	printMessage(_d, 'a');

	std::cout << "Time to process a range of " << _size << " elements with std::vector : "
			  << std::fixed << std::setprecision(5) << ((v_time / (double)CLOCKS_PER_SEC) * 1000) << " us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::deque : "
			  << std::fixed << std::setprecision(5) << ((d_time / (double)CLOCKS_PER_SEC) * 1000) << " us" << std::endl;
}

template <typename T>
void PmergeMe::printMessage(T &container, char c) {
	if (c == 'b')
		std::cout << "Before: ";
	else if (c == 'a')
		std::cout << "After: ";
	for (size_t i = 0; i < container.size(); i++) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::fordJohnson(T &container, clock_t &time) {
	time = clock();

	std::sort(container.begin(), container.end());

	time = clock() - time;
}
