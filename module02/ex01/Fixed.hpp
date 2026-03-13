#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    int              rawValue;
    static const int fractionalBits = 8;

  public:
    ~Fixed(void);
    Fixed(void);
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);

    int    getRawBits(void) const;
    void   setRawBits(int raw);

    float  toFloat(void) const;
    int    toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_point);

#endif
