#pragma once

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include <iomanip>

#include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		~HumanA ();
		HumanA ( std::string name, Weapon &weapon );
		void setName ( std::string name );
		void setWeapon ( Weapon &weapon );
		std::string getName ();
		std::string getWeapon ();
		void attack ();
};

#endif