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

	std::string fList[3] = {"shrubbery creation","robotomy request","presidential pardon"};
	AForm *functions[3] = {new ShruberryCreationForm(ftarget), new RobotomyRequestForm(ftarget), new PresidentialPardonForm(ftarget)};

	for (int i = 0; i < 3; i++) {
		if (fName == fList[i]) {
			std::cout << "Intern creates " << fName << " form" << std::endl;
			return functions[i];
		}
	}
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}