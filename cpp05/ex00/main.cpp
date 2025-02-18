#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat Bob("Bob", 149);
		std::cout << Bob << std::endl;
		Bob.gradeDecrement();
		std::cout << Bob << std::endl;
	}
	catch (const char *e) {
		std::cerr << e << std::endl;
	}
}