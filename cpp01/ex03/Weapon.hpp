#pragma once

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Weapon {
	private:
		std::string _type;
	public:
		Weapon ();
		~Weapon ();
		Weapon ( std::string type );
		void setType ( std::string type );
		std::string getType ();
};

#endif