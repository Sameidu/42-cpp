#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Animal.hpp"

class Dog: virtual public Animal {
	protected:
		std::string _sound;
	public:
		Dog ();
		~Dog ();
		Dog (const Dog &other);

		Dog &operator= (const Dog &other);
		
		void makeSound() const;
		void setSound(std::string sound);
};

#endif