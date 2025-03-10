#include "PmergeMe.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " [file1] [file2] ..." << std::endl;
		return 1;
	}
	try {
		PmergeMe pmergeMe(av + 1, ac - 1);
		pmergeMe.merge();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}