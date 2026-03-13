#include "Fixed.hpp"

// using initialiser list
Fixed::Fixed(void) : rawValue(0) {}

Fixed::Fixed(const int value) : rawValue(value << fractionalBits) {}

Fixed::Fixed(const float value)
    : rawValue(roundf(value * (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed &copy) : rawValue(copy.rawValue) {}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (&copy != this)
        rawValue = copy.rawValue;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (rawValue);
}

void Fixed::setRawBits(int const raw)
{
    rawValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)rawValue / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (rawValue >> fractionalBits);
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (rawValue > rhs.rawValue);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (rawValue < rhs.rawValue);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (rawValue >= rhs.rawValue);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (rawValue <= rhs.rawValue);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (rawValue == rhs.rawValue);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (rawValue != rhs.rawValue);
}

// Explicit Fixed conversion is not required because the
// float constructor [ Fixed(const float value); ] allows implicit conversion

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++()
{
    ++rawValue;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++rawValue;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    --rawValue;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --rawValue;
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_point)
{
    out << fixed_point.toFloat();
    return (out);
}
