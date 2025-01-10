#include "Zombie.hpp"

Zombie* zombieHorde ( int N, std::string name ) {
	Zombie* horde = new Zombie[N];

	std::cout << "Memorie address of horde " << horde << std::endl;
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return horde;
};