#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("none") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) {
	if (this == &other)
		return;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (other.getGradeToSign() < 1 || other.getGradeToExec() < 1)
		throw AForm::GradeTooHighException();
	else if (other.getGradeToSign() > 150 || other.getGradeToExec() > 150)
		throw AForm::GradeTooLowException();
	_target = other._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	std::cout << "*drilling noises* ";
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}