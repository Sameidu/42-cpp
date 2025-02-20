#include "AForm.hpp"

AForm::AForm() : _name("none"), _signed(false), _sign(150), _exec(150) {}

AForm::~AForm() {}

AForm::AForm (std::string name, int sign, int exec) : _name(name), _signed(false), _sign(sign), _exec(exec) {
	if (sign < 1 || exec< 1) 
		throw AForm::GradeTooHighException();
	else if (sign > 150 || exec > 150) 
		throw AForm::GradeTooLowException();
}

AForm::AForm (AForm const &other) : _name(other._name), _sign(other._sign), _exec(other._exec) {
	if (this == &other)
		return;
	*this = other;
}

AForm &AForm::operator=(const AForm &other) {
	if (other._sign < 1 || other._exec < 1)
		throw AForm::GradeTooHighException();
	else if (other._sign > 150 || other._exec > 150)
		throw AForm::GradeTooLowException();
	_signed = other._signed;
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _sign;
}

int AForm::getGradeToExec() const {
	return _exec;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _sign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return "Form is already signed";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm) {
	out << "AForm: " << AForm.getName() << " signed: " << AForm.getSigned()
			  << " grade to sign: " << AForm.getGradeToSign()
			  << " grade to exec: " << AForm.getGradeToExec();
	return out;
}