#include "Zombie.hpp"

Zombie::Zombie () {};

Zombie::Zombie ( std::string name ) {
	this->_name = name;
	announce();
};

Zombie::~Zombie () {
	std::cout << _name << ": Dead!" << std::endl;
};

void	Zombie::announce( void ) {
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

std::string	Zombie::getName () {
	return _name;
};
