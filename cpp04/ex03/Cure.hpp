#pragma once

#ifndef CURE_H
#define CURE_H

#include <string>
#include <iomanip>
#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif