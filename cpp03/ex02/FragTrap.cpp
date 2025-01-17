#include "FragTrap.hpp"

FragTrap::FragTrap () : ClapTrap() {
	std::cout << "FragTrap " << getName() << " is born! [DEFAULT CONSTRUCTOR]" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap () {
	std::cout << "FragTrap " << getName() << " is dead! [DESTRUCTOR]" << std::endl;
}

FragTrap::FragTrap ( std::string name ) : ClapTrap(name) {
	std::cout << "FragTrap " << getName() << " is born! [NAME CONSTRUCTOR]" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap ( const FragTrap& other ) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << getName() << " is born! [COPY CONSTRUCTOR]" << std::endl;
}

FragTrap& FragTrap::operator= ( const FragTrap& other ) {
	if (this == &other)
		return *this;
	this->_name = other.getName();
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "FragTrap " << this->_name << " is born! [ASSIGNATION OPERATOR]" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys () {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << getName() << " Hey guys! High five!" << std::endl;
	}
	else
		std::cout << "FragTrap " << getName() << " please killme guys!" << std::endl;
}