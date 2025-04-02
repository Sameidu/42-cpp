#include "PmergeMe.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " Positive number list" << std::endl;
		return 1;
	}
	try {
		PmergeMeVector v(ac - 1, av + 1);
		v.sortv();
		PmergeMeDeque d(ac - 1, av + 1);
		d.sortd();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}