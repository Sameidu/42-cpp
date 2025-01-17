#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int	main ( void ) {
	DiamondTrap cp0;
	DiamondTrap cp1("FX23W");
	DiamondTrap cp2(cp1);

	cp0.attack("siren");
	cp1.attack("psico");
	cp2.attack("claptrap");
	
	cp0.beRepaired(3);
	cp1.beRepaired(1);
	cp2.beRepaired(0);

	cp0.guardGate();
	cp1.guardGate();
	cp2.guardGate();

	cp0.highFivesGuys();
	cp1.highFivesGuys();
	cp2.highFivesGuys();

	cp0.whoAmI();
	cp1.whoAmI();
	cp2.whoAmI();
	
	return 0;
}