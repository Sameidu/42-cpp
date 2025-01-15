#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fBits = 8;

/* Constructors & destructor */
Fixed::Fixed () : _value(0) {}

Fixed::~Fixed () {}

Fixed::Fixed (Fixed const &copy) {
	*this = copy;
}

Fixed::Fixed (int const value) {
	this->_value = value << this->_fBits;
}

Fixed::Fixed (float const value) {
	this->_value = roundf(value * (1 << this->_fBits));
}

/* Copy assignation operator */

Fixed &Fixed::operator= (Fixed const &copy) {
	if (this == &copy)
		return *this;
	this->_value = copy.getRawBits();
	return *this;
}

/* Overload operator */
std::ostream& operator<< (std::ostream& out, Fixed const& obj) {
	out << obj.toFloat();
	return out;
}

/* Getters & setters */
int Fixed::getRawBits (void) const {
	return this->_value;
}

void Fixed::setRawBits (int const raw) {
	this->_value = raw;
}

/* Conversion de tipos */
float Fixed::toFloat (void) const {
	return (float)this->_value / (1 << this->_fBits);
}

int Fixed::toInt (void) const {
	return this->_value >> this->_fBits;
}

/* Comparasion Operators */
bool Fixed::operator> (Fixed const &copy) {
	return (this->toFloat() > copy.toFloat());
}

bool Fixed::operator< (Fixed const &copy) {
	return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator>= (Fixed const &copy) {
	return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator<= (Fixed const &copy) {
	return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator== (Fixed const &copy) {
	return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!= (Fixed const &copy) {
	return (this->toFloat() != copy.toFloat());
}

/* Arithmetic Operators */
Fixed Fixed::operator+ (Fixed const &copy) {
	Fixed nb;
	nb = Fixed(this->toFloat() + copy.toFloat());
	return nb;
}

Fixed Fixed::operator- (Fixed const &copy) {
	Fixed nb;
	nb = Fixed(this->toFloat() - copy.toFloat());
	return nb;
}

Fixed Fixed::operator* (Fixed const &copy) {
	Fixed nb;
	nb = Fixed(this->toFloat() * copy.toFloat());
	return nb;
}

Fixed Fixed::operator/ (Fixed const &copy) {
	Fixed nb;
	nb = Fixed(this->toFloat() / copy.toFloat());
	return nb;
}

/* inrement & ddecrement ops */
Fixed& Fixed::operator++ () {
	++_value;
	return *this;
}

Fixed& Fixed::operator-- () {
	--_value;
	return *this;
}

Fixed Fixed::operator-- (int) {
	_value--;
	return *this;
}

Fixed Fixed::operator++ (int) {
	_value++;
	return *this;
}

/* min & max */
Fixed const& Fixed::min(Fixed const &nb1, Fixed const &nb2) {
	if (nb1.toFloat() < nb2.toFloat())
		return nb1;
	return nb2;
}

Fixed const& Fixed::max(Fixed const &nb1, Fixed const &nb2) {
	if (nb1.toFloat() > nb2.toFloat())
		return nb1;
	return nb2;
}

Fixed& Fixed::min(Fixed &nb1, Fixed &nb2) {
	if (nb1.toFloat() < nb2.toFloat())
		return nb1;
	return nb2;
}

Fixed& Fixed::max(Fixed &nb1, Fixed &nb2) {
	if (nb1.toFloat() > nb2.toFloat())
		return nb1;
	return nb2;
}