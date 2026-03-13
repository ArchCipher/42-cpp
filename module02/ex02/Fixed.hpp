#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    int              rawValue;
    static const int fractionalBits = 8;

  public:
    ~Fixed(void) {}

    Fixed(void);
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed &copy);

    Fixed              &operator=(const Fixed &copy);

    int                 getRawBits(void) const;
    void                setRawBits(int raw);

    float               toFloat(void) const;
    int                 toInt(void) const;

    // Comparison operators
    bool                operator>(const Fixed &rhs) const;
    bool                operator<(const Fixed &rhs) const;
    bool                operator>=(const Fixed &rhs) const;
    bool                operator<=(const Fixed &rhs) const;
    bool                operator==(const Fixed &rhs) const;
    bool                operator!=(const Fixed &rhs) const;

    // Arithmetic operators
    Fixed               operator+(const Fixed &rhs) const;
    Fixed               operator-(const Fixed &rhs) const;
    Fixed               operator*(const Fixed &rhs) const;
    Fixed               operator/(const Fixed &rhs) const;

    // pre increment
    Fixed              &operator++();
    // post increment
    Fixed               operator++(int);
    // pre decrement
    Fixed              &operator--();
    // post decrement
    Fixed               operator--(int);

    static Fixed       &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed       &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_point);

#endif
