#include "PmergeMe.hpp"

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::PmergeMe() : _size(0), _odd(-1) {}

template <typename T, template <typename, typename> class C>
PmergeMe<T, C>::~PmergeMe() {}

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
PmergeMe<T, C>::PmergeMe(char **av, int ac) : _size(0), _odd(-1) {
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
		if (n < 0) {
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

	_start = clock();

	for (size_t i = 0; i < v.size(); i += 2) {
		if (i + 1 >= v.size())
			continue ;
		else if (v[i] < v[i + 1])
			_data.push_back(std::make_pair(v[i], v[i + 1]));
		else
			_data.push_back(std::make_pair(v[i + 1], v[i]));
	}
}

template <typename T, template <typename, typename> class C>
PmergeMe<T, C> PmergeMe<T, C>::merge(const PmergeMe<T, C> &first, const PmergeMe<T, C> &second) {
	PmergeMe<T, C> merged;
	
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

template <typename T, template <typename, typename> class C>
PmergeMe<T, C> PmergeMe<T, C>::sortedPairs(const C<std::pair<T, T>, std::allocator<std::pair<T, T> > > &data) {
	
	if (data.size() <= 1) {
		PmergeMe<T, C> baseCase;
		baseCase._data = data;
		return baseCase;
	}

	PmergeMe<T, C> first;
	PmergeMe<T, C> second;

	for (size_t i = 0; i < data.size(); i++) {
		if (i < data.size() / 2)
			first._data.push_back(data[i]);
		else
			second._data.push_back(data[i]);
	}
	return merge(sortedPairs(first._data), sortedPairs(second._data));
}

std::vector<size_t> generateJacobsthalIndices(size_t n) {
    std::vector<size_t> indices;
    size_t j0 = 0, j1 = 1;

    while (j1 < n) {
        if (std::find(indices.begin(), indices.end(), j1) == indices.end()) {
            indices.push_back(j1);
        }
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }

    for (size_t i = 0; i < n; ++i) {
        if (std::find(indices.begin(), indices.end(), i) == indices.end()) {
            indices.push_back(i);
        }
    }

    return indices;
}

template <typename T, template <typename, typename> class C>
void PmergeMe<T, C>::insertion(C<T, std::allocator<T> > &sorted, T value) {
	if (sorted.empty()) {
		sorted.push_back(value);
		return;
	}

	size_t left = 0;
	size_t right = sorted.size();

	while (left < right) {
		size_t middle = (left + right) / 2;

		if (sorted[middle] > value)
			right = middle;
		else
			left = middle + 1;
	}

	sorted.insert(sorted.begin() + left, value);
}

template <typename T, template <typename, typename> class C>
void PmergeMe<T, C>::sort(char c) {
	PmergeMe<T, C> pairSorted = sortedPairs(_data);

	C<T, std::allocator<T> > sorted;
	for (size_t i = 0; i < pairSorted._data.size(); i++)
		sorted.push_back(pairSorted._data[i].second);

	std::vector<size_t> jacobsthalOrder = generateJacobsthalIndices(pairSorted._data.size());

	std::cout << "Jacobsthal order: ";
	for (size_t i = 0; i < jacobsthalOrder.size(); i++) {
   		std::cout << jacobsthalOrder[i] << " ";
	}
std::cout << std::endl;

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

	std::cout << "Time to process a range of " << _size << " elements with std::";
	if (c == 'v')
		std::cout << "vector : ";
	else if (c == 'd')
		std::cout << "deque : ";
	std::cout << std::fixed << std::setprecision(5) << ((_start / (double)CLOCKS_PER_SEC)) << " us" << std::endl;
}
