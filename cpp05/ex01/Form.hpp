#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _signed;
		int const _sign;
		int const _exec;

	public:
		Form();
		~Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(Form const &other);

		Form &operator=(const Form &other);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif