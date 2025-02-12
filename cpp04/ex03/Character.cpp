#include "Character.hpp"

Character::Character (std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << getName() << " created" << std::endl;
}

Character::~Character () {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << "Chracter " << getName() << " destroyed" << std::endl; 
}

Character::Character (const Character &other) {
	*this = other;
}

Character &Character::operator= (const Character &other) {
	if (this == &other)
		return *this;
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = other._inventory[i]->clone();
		std::cout << "Materia " << this->_inventory[i]->getType() << " copied" << std::endl;
	}
	std::cout << "Character " << getName() << " copied" << std::endl;
	return *this;
}

std::string const &Character::getName () const {
	return _name;
}

void Character::equip (AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip (int idx) {
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
	else
		std::cout << "No materia in slot " << idx << std::endl;
}

void Character::use (int idx, ICharacter &target) {
	if (this->_inventory[idx] != NULL && idx < 4)
		this->_inventory[idx]->use(target);
	else
		std::cout << "No materia in slot " << idx << std::endl;
}