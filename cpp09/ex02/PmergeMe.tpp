#include "PmergeMe.hpp"

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::PmergeMe() : _size(0) {}

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::PmergeMe(const PmergeMe &other) { *this = other; }

template <typename T, template <typename, typename> class C>
PmergeMe<T, C> &PmergeMe<T, C>::operator=(const PmergeMe &other) {
	if (this != &other) {
		_size = other._size;
		_data = other._data;
	}
	return *this;
}

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::PmergeMe(char **av, int ac) : _size(0), _odd(0) {
	std::stringstream ss;
	std::vector<int> v;

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
		if (n <= 0) {
			throw std::invalid_argument("Only positive numbers are allowed");
		}
		v.push_back(n);
	}
	
	_size = v.size();

	std::set<int> unique_numbers(v.begin(), v.end());
	if (unique_numbers.size() != v.size()) {
		throw std::invalid_argument("Duplicate numbers are not allowed");
	}

	if (_size % 2 != 0)
		_odd = v.back();

	std::cout << "Before sorting: ";
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < v.size(); i += 2) {
		if (i + 1 >= v.size())
			continue ;
		else if (v[i] < v[i + 1])
			_data.push_back(std::make_pair(v[i], v[i + 1]));
		else
			_data.push_back(std::make_pair(v[i + 1], v[i]));
	}

	printPair();
}

template <typename T, template <typename, typename> class C>
void PmergeMe<T, C>::sort() {


	std::cout << "After merging: ";
	printPair();
}

template <typename T,  template <typename, typename> class C>
void PmergeMe<T, C>::printPair() const {
	std::cout << "Data contains " << _size << " elements" << std::endl;
	for (size_t i = 0; i < _data.size(); i++)
		std::cout << "[" << _data[i].first << " " << _data[i].second << "] ";
	if (_odd)
		std::cout << "[" <<_odd << "]";
	std::cout << std::endl;
}