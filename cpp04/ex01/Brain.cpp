#include "Brain.hpp"

Brain::Brain () {
	std::cout << "Brain default constructor called" << std::endl;
	this->_ideasNb = 0;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "No idea";
	}
}

Brain::~Brain () {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain (const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator= (const Brain &other) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
		return "No idea";
	return this->_ideas[index];
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100)
		return;
	this->_ideas[index] = idea;
}
