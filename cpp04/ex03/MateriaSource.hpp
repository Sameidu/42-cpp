#pragma once

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <string>
#include <iomanip>
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:

	protected:

	public:
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif