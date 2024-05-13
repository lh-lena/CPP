#include "Point.hpp"
#include "Fixed.hpp"

Point::Point () : _x(0), _y(0) {}

Point::Point (const float x, const float y) :_x(x), _y(y) {}

Point::Point (const Point& org) {
    *this = org;
}

Point& Point::operator=(const Point& org) {

	(void)org;
    return (*this);
}

Point::~Point ( void ) {}

Fixed	Point::x(void) const {
	return this->_x;
}

Fixed	Point::y(void) const {
	return this->_y;
}


std::ostream	&operator<< (std::ostream& os, const Point& point)
{
	os << "(" << point.x().toFloat() << ", " << point.y().toFloat() << ")";
	return os;
}
