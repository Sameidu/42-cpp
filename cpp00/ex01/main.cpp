#include "Main.hpp"

int	main(void) {
	PhoneBook phoneBook = PhoneBook();
	std::string command;

	std::cout << "Welcome to your phonebook!" << std::endl;
	while (1) {
		std::cout << "Please select a command: [ADD] [SEARCH] [EXIT]" << std::endl;
		getline(std::cin, command);
		for (int i = 0; command[i]; i++)
			command[i] = toupper(command[i]);
		if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT") 
			break;
		else if (command == "ADD")
			phoneBook.addContact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}