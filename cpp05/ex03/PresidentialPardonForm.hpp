#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &other);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		void execute(Bureaucrat const &executor) const;
};

#endif