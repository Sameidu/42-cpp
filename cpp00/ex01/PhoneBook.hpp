#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int nbContacts;

	public:
		PhoneBook();
		~PhoneBook();
		void addContact(int &nbContacts);
		void searchContact(int &nbContacts);
};

#endif