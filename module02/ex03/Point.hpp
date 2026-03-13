#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    const Fixed x;
    const Fixed y;

  public:
    ~Point(void);
    Point(void);
    Point(float a, float b);
    Point(const Fixed &a, const Fixed &b);
    Point(const Point &copy);
    Point       &operator=(const Point &);

    const Fixed &getX(void) const;
    const Fixed &getY(void) const;

    Point        operator-(const Point &rhs) const;

    Fixed        crossProduct(const Point &rhs) const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);

#endif
