#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat Bob("Bob", 149);
		std::cout << Bob << std::endl;
		Bob.gradeDecrement();
		std::cout << Bob << std::endl;
		Bob.gradeDecrement();
		std::cout << Bob << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Bureaucrat Bob("Bob2", 2);
		std::cout << Bob << std::endl;
		Bob.gradeIncrement();
		std::cout << Bob << std::endl;
		Bob.gradeIncrement();
		std::cout << Bob << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		int grade = 189;
		Bureaucrat Bob("Bob3", grade);
		std::cout << Bob << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		int grade = 0;
		Bureaucrat Bob("Bob4", grade);
		std::cout << Bob << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}