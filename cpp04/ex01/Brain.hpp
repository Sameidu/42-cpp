#pragma once

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Brain {
	protected:
		std::string _ideas[100];
		int _ideasNb;
	public:
		Brain ();
		~Brain ();
		Brain (const Brain &other);

		Brain &operator= (const Brain &other);

		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif