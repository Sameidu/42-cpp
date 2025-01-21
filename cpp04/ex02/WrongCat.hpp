#pragma once

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal {
	protected:
		std::string _sound;
	public:
		WrongCat ();
		~WrongCat ();
		WrongCat (const WrongCat &other);

		WrongCat &operator= (const WrongCat &other);
		
		void makeSound() const;
		void setSound(std::string sound);
};

#endif