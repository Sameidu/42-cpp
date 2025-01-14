#include "Fixed.hpp"

Fixed::Fixed () {
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed () {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (Fixed const &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy) {
	if (this == &copy)
		return *this;
	std::cout << "Copy assignation operator called" << std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
