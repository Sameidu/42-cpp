#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_v = other._v;
		_d = other._d;
		_l = other._l;
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
		}
		int n;
		std::stringstream res(num);
		res >> n;
		if (n < 0) {
			throw std::invalid_argument("Only positive numbers are allowed");
		}
		_v.push_back(n);
		_d.push_back(n);
		_l.push_back(n);
		std::cout << "Vector: " << _v.back() << std::endl;
		std::cout << "Deque: " << _d.back() << std::endl;
		std::cout << "List: " << _l.back() << std::endl;
	}
}

void PmergeMe::merge() {

}
