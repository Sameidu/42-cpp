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

std::string Contact::getFirstName() const {
	return (firstName);
}

std::string Contact::getLastName() const {
	return (lastName);
}

std::string Contact::getNickname() const {
	return (nickname);
}

std::string Contact::getPhone() const {
	return (phone);
}

std::string Contact::getDarkestSecret() const {
	return (darkestSecret);
}