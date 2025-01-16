#include "ClapTrap.hpp"

ClapTrap::ClapTrap () : _name("None"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " is born! [DEFAULT CONSTRUCTOR]" << std::endl;
}

ClapTrap::~ClapTrap () {
	std::cout << "ClapTrap " << _name << " is dead! [DESTRUCTOR]" << std::endl;
}

ClapTrap::ClapTrap ( const std::string& name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " is born! [NAME CONSTRUCTOR]" << std::endl;
}

ClapTrap::ClapTrap ( const ClapTrap& other ) {
	std::cout << "ClapTrap " << _name << " is born! [COPY CONSTRUCTOR]" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other ) {
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << this->_name << " is born! [ASSIGNATION OPERATOR]" << std::endl;
	return *this;
}

void ClapTrap::attack ( const std::string& target ) {
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap: " << _name << " attacks " << target
			  << " causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap: " << _name << " is out of energy!" << std::endl;
}

void ClapTrap::takeDamage ( unsigned int amount ) {
	if (_hitPoints > 0 && amount > 0)
	{
		if (amount < _energyPoints)
			_hitPoints -= amount;
		else
			_energyPoints = 0;
		std::cout << "ClapTrap: " << _name << " takes " << amount 
			  << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap: " << _name << " dodge the attack! (Or maybe dead)" << std::endl;
}

void ClapTrap::beRepaired ( unsigned int amount ) {
	if (amount > 0 && _energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap: " << _name << " is repaired by " << amount 
				  << " points!" << std::endl;	
	}
	else
		std::cout << "ClapTrap: " << _name << " can't be repaired!" << std::endl;
}