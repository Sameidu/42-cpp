#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void Contact::setPhone(std::string phone) {
	this->phone = phone;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
	return (this->firstName);
}

std::string Contact::getLastName() {
	return (this->lastName);
}

std::string Contact::getNickname() {
	return (this->nickname);
}

std::string Contact::getPhone() {
	return (this->phone);
}

std::string Contact::getDarkestSecret() {
	return (this->darkestSecret);
}