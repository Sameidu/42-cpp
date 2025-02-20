#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this == &other)
		return *this;
	return *this;
}

AForm *Intern::makeForm(std::string fName, std::string ftarget) {
	if (fName == "shrubbery creation") {
		std::cout << "Intern creates " << fName << " form" << std::endl;
		return new ShruberryCreationForm(ftarget);
	} else if (fName == "robotomy request") {
		std::cout << "Intern creates " << fName << " form" << std::endl;
		return new RobotomyRequestForm(ftarget);
	} else if (fName == "presidential pardon") {
		std::cout << "Intern creates " << fName << " form" << std::endl;
		return new PresidentialPardonForm(ftarget);
	} else {
		throw FormNotFoundException();
	}
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}