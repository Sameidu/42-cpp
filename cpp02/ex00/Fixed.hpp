#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
	private: 
		int _value;
		static const int _fBits = 8;
	public:
		Fixed ();
		~Fixed ();
		Fixed (Fixed const &copy);
		Fixed &operator=(Fixed const &copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);

};

#endif