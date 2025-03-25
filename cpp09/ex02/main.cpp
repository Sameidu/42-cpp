#include "PmergeMe.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: " << av[0] << "Positive number list" << std::endl;
		return 1;
	}
	try {
		PmergeMe<int, std::vector> pmv(av + 1, ac - 1);
		PmergeMe<int, std::deque> pmd(av + 1, ac - 1);
		pmv.sort('v');
		pmd.sort('d');
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}