#include "HumanB.hpp"

HumanB::HumanB () {};

HumanB::~HumanB () {};

HumanB::HumanB ( std::string name ) {
	this->_name = name;
};

void HumanB::setName ( std::string name ) {
	this->_name = name;
};

void HumanB::setWeapon ( Weapon &weapon ) {
	this->_weapon = &weapon;
};

std::string HumanB::getName () {
	return this->_name;
}

std::string HumanB::getWeapon () {
	return this->_weapon->getType();
}

void HumanB::attack () {
	std::cout << this->_name << " attacks with his " << getWeapon() << std::endl;
}