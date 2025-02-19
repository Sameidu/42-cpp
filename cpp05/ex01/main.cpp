#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat Bob("Bob", 149);
		std::cout << Bob << std::endl;
		Form form("Form", 150, 150);
		std::cout << form << std::endl;
		Bob.signForm(form);
		Bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}