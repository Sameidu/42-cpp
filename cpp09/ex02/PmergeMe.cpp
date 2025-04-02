#include "PmergeMe.hpp"

std::vector<size_t> generateJacobsthalIndices(size_t n) {
    std::vector<size_t> indices;
	std::set<size_t> unique_numbers;
    size_t j0 = 0, j1 = 1;

    while (j1 < n) {
        if (unique_numbers.insert(j1).second) {
            indices.push_back(j1);
        }
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }

    for (size_t i = 0; i < n; ++i) {
        if (unique_numbers.insert(i).second) {
            indices.push_back(i);
        }
    }

    return indices;
}

PmergeMeVector::PmergeMeVector() : _size(0), _odd(-1) {}

PmergeMeVector::~PmergeMeVector() {}

PmergeMeVector::PmergeMeVector(const PmergeMeVector &other) { *this = other; }

PmergeMeVector &PmergeMeVector::operator=(const PmergeMeVector &other) {
	if (this != &other) {
		_size = other._size;
		_odd = other._odd;
		_start = other._start;
		_data = other._data;
	}
	return *this;
}

PmergeMeVector::PmergeMeVector(int ac, char **av) : _size(0), _odd(-1) {
	std::stringstream ss;
	std::vector<int> v;

	_start = clock();

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
		v.push_back(n);
	}
	
	_size = v.size();

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
}

void  PmergeMeVector::printTime(const PmergeMeVector v) {
	std::cout << "Time to process a range of " << v._size << " elements with std::vector ";
	std::cout << std::fixed << std::setprecision(5) << ((v._start / (double)CLOCKS_PER_SEC)) << " us" << std::endl;
}

void PmergeMeVector::sortv() {
	PmergeMeVector pairSorted = sortedPairs(_data);

	std::vector<int> sorted;
	for (size_t i = 0; i < pairSorted._data.size(); i++)
		sorted.push_back(pairSorted._data[i].second);

	std::vector<size_t> jacobsthalOrder = generateJacobsthalIndices(pairSorted._data.size());

	for (size_t i = 0; i < jacobsthalOrder.size(); i++) {
		size_t index = jacobsthalOrder[i];
		insertion(sorted, pairSorted._data[index].first);
	}

	if (_odd != -1)
		insertion(sorted, _odd);

	std::cout << "After sorting: ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
}

PmergeMeVector PmergeMeVector::merge(const PmergeMeVector &first, const PmergeMeVector &second) {
	PmergeMeVector merged;

	size_t i = 0;
	size_t j = 0;

	while (i < first._data.size() && j < second._data.size()) {
		if (first._data[i].second < second._data[j].second)
			merged._data.push_back(first._data[i++]);
		else
			merged._data.push_back(second._data[j++]);
	}

	while (i < first._data.size())
		merged._data.push_back(first._data[i++]);
	while (j < second._data.size())
		merged._data.push_back(second._data[j++]);

	return merged;
}

PmergeMeVector PmergeMeVector::sortedPairs(const std::vector<std::pair<int, int> > &data) {
	if (data.size() <= 1) {
		PmergeMeVector baseCase;
		baseCase._data = data;
		return baseCase;
	}

	PmergeMeVector first;
	PmergeMeVector second;

	for (size_t i = 0; i < data.size(); i++) {
		if (i < data.size() / 2)
			first._data.push_back(data[i]);
		else
			second._data.push_back(data[i]);
	}

	first = sortedPairs(first._data);
	second = sortedPairs(second._data);

	return merge(first, second);
}

void PmergeMeVector::insertion(std::vector<int> &sorted, int value) {
	if (sorted.empty()) {
		sorted.push_back(value);
		return;
	}

	size_t left = 0;
	size_t right = sorted.size();

	while (left < right) {
		size_t middle = left + (right - left) / 2;

		if (sorted[middle] > value)
			right = middle;
		else
			left = middle + 1;
	}

	sorted.insert(sorted.begin() + left, value);
}

PmergeMeDeque::PmergeMeDeque() : _size(0), _odd(-1) {}

PmergeMeDeque::~PmergeMeDeque() {}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &other) { *this = other; }

PmergeMeDeque &PmergeMeDeque::operator=(const PmergeMeDeque &other) {
	if (this != &other) {
		_size = other._size;
		_odd = other._odd;
		_start = other._start;
		_data = other._data;
	}
	return *this;
}

PmergeMeDeque::PmergeMeDeque(int ac, char **av) : _size(0), _odd(-1) {
	std::stringstream ss;
	std::deque<int> d;

	_start = clock();

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
		d.push_back(n);
	}
	
	_size = d.size();

	if (_size % 2 != 0)
		_odd = d.back();

	std::cout << "Before sorting: ";
	for (size_t i = 0; i < d.size(); i++) {
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < d.size(); i += 2) {
		if (i + 1 >= d.size())
			continue ;
		else if (d[i] < d[i + 1])
			_data.push_back(std::make_pair(d[i], d[i + 1]));
		else
			_data.push_back(std::make_pair(d[i + 1], d[i]));
	}
}

void  PmergeMeDeque::printTime(const PmergeMeDeque d) {
	std::cout << "Time to process a range of " << d._size << " elements with std::deque ";
	std::cout << std::fixed << std::setprecision(5) << ((d._start / (double)CLOCKS_PER_SEC)) << " us" << std::endl;
}

void PmergeMeDeque::sortd() {
	PmergeMeDeque pairSorted = sortedPairs(_data);

	std::deque<int> sorted;
	for (size_t i = 0; i < pairSorted._data.size(); i++)
		sorted.push_back(pairSorted._data[i].second);

	std::vector<size_t> jacobsthalOrder = generateJacobsthalIndices(pairSorted._data.size());

	for (size_t i = 0; i < jacobsthalOrder.size(); i++) {
		size_t index = jacobsthalOrder[i];
		insertion(sorted, pairSorted._data[index].first);
	}

	if (_odd != -1)
		insertion(sorted, _odd);

	std::cout << "After sorting: ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
}

PmergeMeDeque PmergeMeDeque::merge(const PmergeMeDeque &first, const PmergeMeDeque &second) {
	PmergeMeDeque merged;

	size_t i = 0;
	size_t j = 0;

	while (i < first._data.size() && j < second._data.size()) {
		if (first._data[i].second < second._data[j].second)
			merged._data.push_back(first._data[i++]);
		else
			merged._data.push_back(second._data[j++]);
	}

	while (i < first._data.size())
		merged._data.push_back(first._data[i++]);
	while (j < second._data.size())
		merged._data.push_back(second._data[j++]);

	return merged;
}

PmergeMeDeque PmergeMeDeque::sortedPairs(const std::deque<std::pair<int, int> > &data) {
	if (data.size() <= 1) {
		PmergeMeDeque baseCase;
		baseCase._data = data;
		return baseCase;
	}

	PmergeMeDeque first;
	PmergeMeDeque second;

	for (size_t i = 0; i < data.size(); i++) {
		if (i < data.size() / 2)
			first._data.push_back(data[i]);
		else
			second._data.push_back(data[i]);
	}

	first = sortedPairs(first._data);
	second = sortedPairs(second._data);

	return merge(first, second);
}

void PmergeMeDeque::insertion(std::deque<int> &sorted, int value) {
	if (sorted.empty()) {
		sorted.push_back(value);
		return;
	}

	size_t left = 0;
	size_t right = sorted.size();

	while (left < right) {
		size_t middle = left + (right - left) / 2;

		if (sorted[middle] > value)
			right = middle;
		else
			left = middle + 1;
	}

	sorted.insert(sorted.begin() + left, value);
}