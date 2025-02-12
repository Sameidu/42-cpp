#include "Dog.hpp"

Dog::Dog () : Animal() {
	setType("Dog");
	setSound("Wouf!");
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog () {
	std::cout << "Dog destructor called" << std::endl;
	if (_brain)
		delete _brain;
}

Dog::Dog (const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator= (const Dog &other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	_brain = new Brain(*other._brain);
	_sound = other._sound;
	return *this;
}

void Dog::makeSound() const {
	std::cout << _sound << std::endl;
}

void Dog::setSound(std::string sound) {
	_sound = sound;
}

Brain *Dog::getBrain() const {
	return _brain;
}