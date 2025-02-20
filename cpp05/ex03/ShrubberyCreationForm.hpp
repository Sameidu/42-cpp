#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <exception>
#include "AForm.hpp"

class ShruberryCreationForm : public AForm {
	private:
		std::string _target;

	public: 
		ShruberryCreationForm();
		~ShruberryCreationForm();
		ShruberryCreationForm(std::string target);
		ShruberryCreationForm(ShruberryCreationForm const &other);

		ShruberryCreationForm &operator=(const ShruberryCreationForm &other);

		void execute(Bureaucrat const &executor) const;
};

#endif