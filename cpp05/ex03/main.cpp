#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	try {
		Bureaucrat Bob("Bob", 3);
		std::cout << Bob << std::endl;
		PresidentialPardonForm form("President");
		Bob.executeForm(form);
		Bob.signForm(form);
		Bob.executeForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat Jim("Jim", 13);
		std::cout << Jim << std::endl;
		RobotomyRequestForm form("Robot");
		Jim.executeForm(form);
		Jim.signForm(form);
		Jim.executeForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat Tim("Tim", 7);
		std::cout << Tim << std::endl;
		ShruberryCreationForm form("Shrub");
		Tim.executeForm(form);
		Tim.signForm(form);
		Tim.executeForm(form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}