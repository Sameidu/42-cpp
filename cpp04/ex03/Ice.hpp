#pragma once

#ifndef ICE_H
#define ICE_H

#include <string>
#include <iomanip>
#include <iostream>
#include "IMateriaSource.hpp"

class Ice: public AMateria {
	public:
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif