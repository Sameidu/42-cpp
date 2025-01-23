#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iomanip>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter {
	protected:
		std::string _name;
		AMateria *_inventory[4];

	public:
		Character ();
		~Character();
		Character (std::string name);
		Character (const Character &other);

		Character &operator= (const Character &other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif