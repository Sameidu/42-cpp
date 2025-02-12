#include "Cat.hpp"

Cat::Cat () : Animal() {
	setType("Cat");
	setSound("Meow!");
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat () {
	std::cout << "Cat destructor called" << std::endl;
	if (_brain)
		delete _brain;
}

Cat::Cat (const Cat &other) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator= (const Cat &other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	_brain = new Brain(*other._brain);
	_sound = other._sound;
	return *this;
}

void Cat::makeSound() const {
	std::cout << _sound << std::endl;
}

void Cat::setSound(std::string sound) {
	_sound = sound;
}

Brain *Cat::getBrain() const {
	return _brain;
}