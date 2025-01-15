#include "Fixed.hpp"

const int Fixed::_fBits = 8;

/* Constructors & destructor */
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

Fixed::Fixed (int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fBits;
}

Fixed::Fixed (float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fBits));
}

/* Copy assignation operator */

Fixed &Fixed::operator=(Fixed const &copy) {
	if (this == &copy)
		return *this;
	std::cout << "Copy assignation operator called" << std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

/* Overload operator */
std::ostream& operator<<(std::ostream& out, Fixed const& obj) {
	out << obj.toFloat();
	return out;
}

/* Getters & setters */
int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

/* Conversion de tipos */
float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_fBits);
}

int Fixed::toInt(void) const {
	return this->_value >> this->_fBits;
}
