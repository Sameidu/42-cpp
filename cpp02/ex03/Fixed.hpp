#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <ostream>

class Fixed {
	private: 
		int _value;
		static const int _fBits;
	public:
		Fixed ();
		~Fixed ();
		Fixed (Fixed const &copy);
		Fixed (int const value);
		Fixed (float const value);
		
		Fixed& operator=(Fixed const &copy);

		bool operator>(Fixed const &copy);
		bool operator<(Fixed const &copy);
		bool operator>=(Fixed const &copy);
		bool operator<=(Fixed const &copy);
		bool operator==(Fixed const &copy);
		bool operator!=(Fixed const &copy);

		Fixed operator+(Fixed const &copy);
		Fixed operator-(Fixed const &copy);
		Fixed operator*(Fixed const &copy);
		Fixed operator/(Fixed const &copy);

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed &nb1, Fixed &nb2);
		static Fixed& max(Fixed &nb1, Fixed &nb2);
		static Fixed const& min(Fixed const &nb1, Fixed const &nb2);
		static Fixed const& max(Fixed const &nb1, Fixed const &nb2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, Fixed const& obj);

#endif