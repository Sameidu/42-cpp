#include "Zombie.hpp"

int	main( void ) {
	std::string line;
	Zombie* zom1;

	std::cout << "Name your Zombie" << std::endl;
	getline(std::cin, line);
	zom1 = newZombie(line);
	randomChump("Luis");
	delete(zom1);
	return 0;
}