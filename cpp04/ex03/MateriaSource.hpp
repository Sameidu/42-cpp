#pragma once

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <string>
#include <iomanip>
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	protected:
		AMateria *_materia[4];
		
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource (const MateriaSource &other);

		MateriaSource &operator= (const MateriaSource &toher);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif