#include "Point.hpp"

Point::Point () : _x(0), _y(0) {};

Point::~Point () {};

Point::Point (float const valuex, float const valuey) : _x(valuex), _y(valuey) {};

Point::Point (Point const &copy) : _x(copy._x), _y(copy._y) {
	*this = copy;
}

Point& Point::operator= (Point const &copy) {
	if (this == &copy)
		return *this;
	return *this;
}

Fixed	Point::getX() const  {
	return this->_x.toFloat();
}

Fixed	Point::getY () const {
	return this->_y.toFloat();
}

std::ostream& operator<< (std::ostream& out, Point const& obj) {
	out << obj.getX() << " " << obj.getY();
	return out;
}