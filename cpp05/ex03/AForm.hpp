#pragma once

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _signed;
		int const _sign;
		int const _exec;

	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(AForm const &other);

		AForm &operator=(const AForm &other);

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

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);

#endif