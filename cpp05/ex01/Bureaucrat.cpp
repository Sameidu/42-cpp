#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("none"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat (std::string name, int grade) : _name(name) {
	if (grade < 1) 
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150) 
		throw Bureaucrat::GradeTooLowException();
	else 
		_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &other) : _name(other._name) {
	if (this == &other)
		return;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (other._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (other._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::gradeIncrement() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::gradeDecrement() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) {
	if (_grade < form.getGradeToSign())
	{
		form.beSigned(*this); 
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	else if (form.getSigned())
		std::cout << _name << " cannot sign " << form.getName() << " because form is already signed" << std::endl;
	else
		std::cout << _name << " cannot sign " << form.getName() << " because grade is too low" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}