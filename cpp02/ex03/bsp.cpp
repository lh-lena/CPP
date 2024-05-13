#include "Point.hpp"

bool    bsp( Point const a, Point const b, Point const c, Point const point)
{
    // Fixed t = (a.x() * (b.y() - c.y()) + b.x() * (c.y() - a.y()) + c.x() * (a.y() - b.y())) / 2;
    // Fixed t1 = (point.x() * (b.y() - c.y()) + b.x() * (c.y() - point.y()) + c.x() * (point.y() - b.y())) / 2;
    // Fixed t2 = (a.x() * (point.y() - c.y()) + point.x() * (c.y() - a.y()) + c.x() * (a.y() - point.y())) / 2;
    // Fixed t3 = (a.x() * (b.y() - point.y()) + b.x() * (point.y() - a.y()) + point.x() * (a.y() - b.y())) / 2;
    // return (t == (t1 + t2 + t3));
    Fixed t = (b.x() - a.x()) * (c.y() - a.y()) - (b.y() - a.y()) * (c.x() - a.x());
    Fixed d1 = (b.x() - a.x()) * (point.y() - a.y()) - (b.y() - a.y()) * (point.x() - a.x());
    Fixed d2 = (b.x() - point.x()) * (c.y() - point.y()) - (b.y() - point.y()) * (c.x() - point.x());
    Fixed d3 = (point.x() - c.x()) * (a.y() - c.y()) - (point.y() - c.y()) * (a.x() - c.x());
    return ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0));
}

