#include "HumanA.hpp"

HumanA::~HumanA () {};

HumanA::HumanA ( std::string name, Weapon &weapon ) : _weapon(weapon) {
	this->_name = name;
};

void HumanA::setName ( std::string name ) {
	this->_name = name;
}

void HumanA::setWeapon ( Weapon &weapon ) {
	this->_weapon = weapon;
}

std::string HumanA::getName () {
	return this->_name;
}

std::string HumanA::getWeapon () {
	return this->_weapon.getType();
}

void HumanA::attack () {
	std::cout << this->_name << " attacks with his " << getWeapon() << std::endl;
}