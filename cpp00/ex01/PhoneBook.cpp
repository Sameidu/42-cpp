#include "PhoneBook.hpp"

PhoneBook::PhoneBook () : nbContacts(0) {}

PhoneBook::~PhoneBook () {}

void PhoneBook::addContact() {
	std::string line;
	
	if (nbContacts == 8) {
		std::cout << "Phonebook is full, starting from the beginning" << std::endl;
		nbContacts = 0;
	}
	while (line.empty()) {
		std::cout << "Please enter the first name: ";
		std::getline(std::cin, line);
		contacts[nbContacts].setFirstName(line);
	}
	line.clear();
	while (line.empty()) {
		std::cout << "Please enter the last name: ";
		std::getline(std::cin, line);
		if (!line.empty())
			contacts[nbContacts].setLastName(line);
		else
			std::cout << "Last name cannot be empty" << std::endl;
	}
	line.clear();
	while (line.empty()) {
		std::cout << "Please enter the nickname: ";
		std::getline(std::cin, line);
		if (!line.empty())
			contacts[nbContacts].setNickname(line);
		else
			std::cout << "Nickname cannot be empty" << std::endl;
	}
	line.clear();
	while (line.empty()) {
		std::cout << "Please enter the phone number: ";
		std::getline(std::cin, line);
		if (!line.empty())
			contacts[nbContacts].setPhone(line);
		else
			std::cout << "Phone number cannot be empty" << std::endl;
	}
	line.clear();
	while (line.empty()) {
		std::cout << "Please enter the darkest secret: ";
		std::getline(std::cin, line);
		if (!line.empty())
			contacts[nbContacts].setDarkestSecret(line);
		else
			std::cout << "Darkest secret cannot be empty" << std::endl;
	}
	nbContacts++;
	std::cout << "Contact added successfully" << std::endl;
	std::cout << "Total contacts: " << nbContacts << std::endl << std::endl;
}

void PhoneBook::searchContact() {
	std::string line;

	if (nbContacts == 0) {
		std::cout << "No contacts available" << std::endl << std::endl;
		return ;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		if (contacts[i].getFirstName().length() > 9)
			std::cout << std::setw(9) << contacts[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
		if (contacts[i].getLastName().length() > 9)
			std::cout << std::setw(9) << contacts[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10)<< contacts[i].getLastName() << "|";
		if (contacts[i].getNickname().length() > 9)
			std::cout << std::setw(9) << contacts[i].getNickname().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << contacts[i].getNickname() << "|";
		std::cout << std::endl << "--------------------------------------------" << std::endl;
	}
	std::cout << std::endl << "Please enter the index of the contact: ";
	std::getline(std::cin, line);
	if (line.length() == 1 && line[0] >= '1' && line[0] <= '8') {
		int index = line[0] - '1';
		if (index > 8 || index < 0 || contacts[index].getFirstName().empty()) {
			std::cout << "Invalid index" << std::endl << std::endl;
			return ;
		}
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone: " << contacts[index].getPhone() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl << std::endl;
}