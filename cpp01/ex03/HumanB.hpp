#pragma once

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include <iomanip>

#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB ();
		~HumanB ();
		HumanB ( std::string name );
		void setName ( std::string name );
		void setWeapon ( Weapon &weapon );
		std::string getName ();
		std::string getWeapon ();
		void attack ();
};

#endif