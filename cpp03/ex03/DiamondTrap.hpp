#pragma once

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <string>
#include <iostream>
#include <iomanip>

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap ();
		~DiamondTrap ();
		DiamondTrap ( const std::string& name );
		DiamondTrap ( const DiamondTrap& other );
		
		DiamondTrap& operator= (const DiamondTrap &other);

		void	whoAmI();
};


#endif