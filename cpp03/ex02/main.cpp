#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main ( void ) {
	FragTrap cp0;
	FragTrap cp1("FX23W");
	FragTrap cp2(cp1);

	cp0.attack("siren");
	cp1.attack("psico");
	cp2.attack("claptrap");
	
	cp0.beRepaired(3);
	cp1.beRepaired(1);
	cp2.beRepaired(0);

	cp0.highFivesGuys();
	cp1.highFivesGuys();
	cp2.highFivesGuys();
}