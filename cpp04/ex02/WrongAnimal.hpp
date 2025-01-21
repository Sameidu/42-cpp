#pragma once

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>
#include <iomanip>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal ();
		virtual ~WrongAnimal ();
		WrongAnimal (const WrongAnimal &other);

		WrongAnimal &operator= (const WrongAnimal &other);

		std::string getType() const;
		void setType(std::string type);

		virtual void makeSound() const;
};

#endif