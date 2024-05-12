#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

public:
    Point ();
    Point (const float x, const float y);
    Point (const Point& org);
    Point& operator=(const Point& org);
    ~Point( void );
    Fixed x( void ) const;
    Fixed y( void ) const;

private:
    const Fixed _x;
    const Fixed _y;
};

std::ostream	&operator<< (std::ostream& os, Point const& point);

#endif