#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat( std::string name, int grade);
		Bureaucrat( Bureaucrat const &other);

		Bureaucrat &operator=(const Bureaucrat &other);

		void	gradeIncrement();
		void	gradeDecrement();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		std::string getName() const;
		int getGrade() const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif