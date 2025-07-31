#include "Harl.hpp"

Harl::Harl () {
	std::cout << "Harl is born." << std::endl;
};

Harl::~Harl () {
	std::cout << "Harl is dead." << std::endl;
};

void Harl::complain ( std::string level ) {
	int key = 0;

	if ( level == "DEBUG" )
		key = 1;
	else if ( level == "INFO" )
		key = 2;
	else if ( level == "WARNING" )
		key = 3;
	else if ( level == "ERROR" )
		key = 4;

	switch ( key ) {
		case 1:
			debug();
			// fall through
		case 2:
			info();
			// fall through
		case 3:
			warning();
			// fall through
		case 4:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
};

void Harl::debug ( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
			  << "I really do!" << std::endl;
};

void Harl::info ( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
};

void Harl::warning ( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years whereas you started working here since last month." << std::endl;
};

void Harl::error ( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};
