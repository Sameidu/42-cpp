#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
	std::cout << "MateriaSource created" << std::endl;
}

MateriaSource::~MateriaSource () {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
	std::cout << "Materia destroyed" << std::endl; 
}

MateriaSource::MateriaSource (const MateriaSource &other) {
	*this = other;
}

MateriaSource &MateriaSource::operator= (const MateriaSource &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
		this->_materia[i] = other._materia[i];
	}
	return *this;
}

void MateriaSource::learnMateria (AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria (std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i]->getType() == type) {
			std::cout << "Creating materia " << type << std::endl;
			return this->_materia[i]->clone();
		}
	}
	std::cout << "Cannot create materia " << type << std::endl;
	return NULL;
}