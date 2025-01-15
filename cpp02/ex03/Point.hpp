#pragma once

#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <ostream>
#include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point ();
		~Point ();
		Point (float const valuex, float const valuey);
		Point (Point const &copy);
		Point& operator=(Point const &copy);
		Fixed getX () const;
		Fixed getY () const;
};

std::ostream& operator<< (std::ostream& out, Point const& obj);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif