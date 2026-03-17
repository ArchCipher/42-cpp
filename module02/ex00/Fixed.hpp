#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    int              rawValue;
    static const int fractionalBits = 8;

  public:
    ~Fixed(void);
    Fixed(void);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);

    int    getRawBits(void) const;
    void   setRawBits(int raw);
};

#endif
