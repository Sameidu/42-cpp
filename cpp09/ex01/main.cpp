#include "RPN.hpp"

int main (int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./rpn \"[RPN expression]\"" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		rpn.checkArg(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}