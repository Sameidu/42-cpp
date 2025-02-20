#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &other);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		void execute(Bureaucrat const &executor) const;
};

#endif