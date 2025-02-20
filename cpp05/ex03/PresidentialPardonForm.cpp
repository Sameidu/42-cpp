#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("none") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {
	if (this == &other)
		return;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (other.getGradeToSign() < 1 || other.getGradeToExec() < 1)
		throw AForm::GradeTooHighException();
	else if (other.getGradeToSign() > 150 || other.getGradeToExec() > 150)
		throw AForm::GradeTooLowException();
	_target = other._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
