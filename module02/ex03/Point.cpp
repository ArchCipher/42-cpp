#include "Point.hpp"

Point::~Point(void) {}

Point::Point(void) : x(0), y(0) {}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point::Point(const Fixed &a, const Fixed &b) : x(a), y(b) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point &Point::operator=(const Point &)
{
    return (*this);
}

const Fixed &Point::getX(void) const
{
    return (x);
}

const Fixed &Point::getY(void) const
{
    return (y);
}

Point Point::operator-(const Point &rhs) const
{
    return (Point(x - rhs.x, y - rhs.y));
}

Fixed Point::crossProduct(const Point &rhs) const
{
    return (x * rhs.y - y * rhs.x);
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << "(" << point.getX() << "," << point.getY() << ")";
    return (out);
}
