#include "Zombie.hpp"

int	main( void ) {
	Zombie* horde = zombieHorde(7, "none");
	std::cout << "Memorie address of horde " << horde << std::endl;
	std::cout << "Killing all zombie" << std::endl;
	delete [] horde;
	return 0;
}