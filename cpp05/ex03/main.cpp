#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	try {
		Bureaucrat Bob("Bob", 3);
		std::cout << Bob << std::endl;
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "President");
		std::cout << *form << std::endl;
		Bob.executeForm(*form);
		Bob.signForm(*form);
		Bob.executeForm(*form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat Jim("Jim", 13);
		std::cout << Jim << std::endl;
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "Claptrap");
		std::cout << *form << std::endl;
		Jim.executeForm(*form);
		Jim.signForm(*form);
		Jim.executeForm(*form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat Tim("Tim", 7);
		std::cout << Tim << std::endl;
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "Tree");
		std::cout << *form << std::endl;
		Tim.executeForm(*form);
		Tim.signForm(*form);
		Tim.executeForm(*form);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Intern intern;
		AForm *form = intern.makeForm("world destruction", "God");
		std::cout << *form << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}