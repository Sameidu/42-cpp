#include "Animal.hpp"

Animal::Animal () : _type("none") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal () {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal (const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator= (const Animal &other) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

void Animal::setType(std::string type) {
	_type = type;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound!" << std::endl;
}