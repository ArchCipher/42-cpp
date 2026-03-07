#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    int              raw_value;
    static const int fractional_bits = 8;

  public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &);
    Fixed &operator=(const Fixed &copy);
    ~Fixed(void);

    int   getRawBits(void) const;
    void  setRawBits(int const raw);

    float toFloat(void) const;
    int   toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_point);

#endif
