#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>
#include <iomanip>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void announce( void ); 
		std::string getName ();
		void setName (std::string name );
};

Zombie* zombieHorde( int N, std::string name );

#endif