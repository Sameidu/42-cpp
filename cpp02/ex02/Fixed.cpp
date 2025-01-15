#include "Fixed.hpp"

const int Fixed::_fBits = 8;

Fixed::Fixed () : _value(0) {
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

Fixed::Fixed (int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fBits;
}

Fixed::Fixed (float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = std::roundf(value * (1 << this->_fBits));
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_fBits);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_fBits;
}