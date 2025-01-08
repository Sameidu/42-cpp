#include "Main.hpp"

int	main(void) {
	PhoneBook phoneBook = PhoneBook();
	std::string command;
	int nbContacts = 0;

	std::cout << "Welcome to your phonebook!" << std::endl;
	while (1) {
		std::cout << "Please select a command: [ADD] [SEARCH] [EXIT]" << std::endl;
		getline(std::cin, command);
		for (int i = 0; command[i]; i++)
			command[i] = toupper(command[i]);
		if (command == "SEARCH")
			phoneBook.searchContact(nbContacts);
		else if (command == "EXIT") 
			break;
		else if (command == "ADD")
		{
			if (nbContacts == 8)
			{
				nbContacts = 0;
				std::cout << "Phonebook is full, starting from the beginning" << std::endl;
			}
			phoneBook.addContact(nbContacts);
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}