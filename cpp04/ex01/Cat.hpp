#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: virtual public Animal {
	private:
		Brain *_brain;
	protected:
		std::string _sound;
	public:
		Cat ();
		~Cat ();
		Cat (const Cat &other);

		Cat &operator= (const Cat &other);
		
		void makeSound() const;
		void setSound(std::string sound);
		Brain *getBrain() const;
};

#endif