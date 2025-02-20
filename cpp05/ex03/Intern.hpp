#pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern ();
		~Intern ();
		Intern (Intern const &other);
		
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string fName, std::string ftarget);

		class FormNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif