#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    int raw_value;
    static const int fractional_bits = 8;

  public:
    Fixed(void);

    // copy constructor
    Fixed(const Fixed &);

    // copy assignment operator
    Fixed &operator=(const Fixed &copy);

    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
