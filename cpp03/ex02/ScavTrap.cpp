#include "ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap() {
	std::cout << "ScavTrap " << getName() << " is born! [DEFAULT CONSTRUCTOR]" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap ( const std::string& name ) : ClapTrap(name) {
	std::cout << "ScavTrap " << getName() << " is born! [NAME CONSTRUCTOR]" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap ( const ScavTrap& other ) : ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap " << getName() << " is born! [COPY CONSTRUCTOR]" << std::endl;
}

ScavTrap& ScavTrap::operator= ( const ScavTrap& other ) {
	if (this == &other)
		return *this;
	this->_name = other.getName();
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ScavTrap " << this->_name << " is born! [ASSIGNATION OPERATOR]" << std::endl;
	return *this;

}

ScavTrap::~ScavTrap () {
	std::cout << "ScavTrap " << getName() << " is dead! [DESTRUCTOR]" << std::endl;
}

void	ScavTrap::attack ( const std::string& target ) {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << getName() << " attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << " is out of energy!" << std::endl;
}

void ScavTrap::guardGate () {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << getName() << " has entered in Gate keeper mode!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << " can't change mode!" << std::endl;
}