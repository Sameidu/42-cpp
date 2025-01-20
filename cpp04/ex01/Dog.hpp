#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: virtual public Animal {
	private:
		Brain *_brain;
	protected:
		std::string _sound;
	public:
		Dog ();
		~Dog ();
		Dog (const Dog &other);

		Dog &operator= (const Dog &other);
		
		void makeSound() const;
		void setSound(std::string sound);
		Brain *getBrain() const;
};

#endif