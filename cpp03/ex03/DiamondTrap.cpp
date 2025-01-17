#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap () : ClapTrap () {
	_name = this->ClapTrap::_name;
	_name = _name.append("_clap_name");
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " is born! [DEFAULT CONSTRUCTOR]" << std::endl;
}

DiamondTrap::~DiamondTrap () {
	std::cout << "DiamondTrap " << _name << " is dead! [DESTRUCTOR]" << std::endl;
}

DiamondTrap::DiamondTrap ( const std::string& name ) : ClapTrap(name) {
	_name = this->ClapTrap::_name;
	_name = _name.append("_clap_name");
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " is born! [NAME CONSTRUCTOR]" << std::endl;
}

DiamondTrap::DiamondTrap ( const DiamondTrap& other ) {
	*this = other;
	std::cout << "DiamondTrap " << _name << " is born! [COPY CONSTRUCTOR]" << std::endl;
}

DiamondTrap& DiamondTrap::operator= ( const DiamondTrap &other ) {
	if (this == &other)
		return *this;
	_name = other.ClapTrap::_name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap " << _name << " is born! [ASSIGNATION OPERATOR]" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI () {
	std::cout << "DiamondTrap: " << _name << " is " << this->ClapTrap::_name << "!" << std::endl;
}