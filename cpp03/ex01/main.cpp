#include "ClapTrap.hpp"

int	main ( void ) {
	ClapTrap cp0;
	ClapTrap cp1("FX23W");
	ClapTrap cp2(cp1);

	cp0.attack("siren");
	cp1.attack("psico");
	cp2.attack("claptrap");
	
	cp0.beRepaired(3);
	cp1.beRepaired(1);
	cp2.beRepaired(0);

	cp0.takeDamage(3);
	cp1.takeDamage(1);
	cp2.takeDamage(0);
}