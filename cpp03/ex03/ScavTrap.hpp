#pragma once

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
    public:
        ScavTrap ();
        ~ScavTrap ();
		ScavTrap ( const std::string& name );
		ScavTrap ( const ScavTrap& other );
		
		ScavTrap& operator= (const ScavTrap &other);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif