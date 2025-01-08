#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phone;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickname(std::string nickname);
		void setPhone(std::string phone);
		void setDarkestSecret(std::string darkestSecret);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhone();
		std::string getDarkestSecret();
};

#endif