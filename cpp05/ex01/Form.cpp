#include "Form.hpp"

Form::Form() : _name("none"), _signed(false), _sign(150), _exec(150) {}

Form::~Form() {}

Form::Form (std::string name, int sign, int exec) : _name(name), _signed(false), _sign(sign), _exec(exec) {
	if (sign < 1 || exec< 1) 
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150) 
		throw Form::GradeTooLowException();
}

Form::Form (Form const &other) : _name(other._name), _sign(other._sign), _exec(other._exec) {
	if (this == &other)
		return;
	*this = other;
}

Form &Form::operator=(const Form &other) {
	if (other._sign < 1 || other._exec < 1)
		throw Form::GradeTooHighException();
	else if (other._sign > 150 || other._exec > 150)
		throw Form::GradeTooLowException();
	_signed = other._signed;
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _sign;
}

int Form::getGradeToExec() const {
	return _exec;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _sign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *Form::FormAlreadySignedException::what() const throw() {
	return "Form is already signed";
}

const char *Form::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << "Form: " << form.getName() << " signed: " << form.getSigned()
			  << " grade to sign: " << form.getGradeToSign()
			  << " grade to exec: " << form.getGradeToExec();
	return out;
}