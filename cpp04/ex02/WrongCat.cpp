#include "WrongCat.hpp"

WrongCat::WrongCat () : WrongAnimal() {
	setType("WrongCat");
	setSound("uwu!");
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat () {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat (const WrongCat &other) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator= (const WrongCat &other) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	_sound = other._sound;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << _sound << std::endl;
}

void WrongCat::setSound(std::string sound) {
	_sound = sound;
}