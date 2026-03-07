#include "Fixed.hpp"

// using initialiser list
Fixed::Fixed(void) : raw_value(0)
{
}

Fixed::Fixed(const int value) : raw_value(value << fractional_bits)
{
}

Fixed::Fixed(const float value)
    : raw_value(roundf(value * (1 << fractional_bits)))
{
}

Fixed::Fixed(const Fixed &copy) : raw_value(copy.raw_value)
{
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (&copy != this)
        raw_value = copy.raw_value;
    return (*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
    return (raw_value);
}

void Fixed::setRawBits(int const raw)
{
    raw_value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)raw_value / (1 << fractional_bits));
}

int Fixed::toInt(void) const
{
    return (raw_value >> fractional_bits);
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (raw_value > rhs.raw_value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (raw_value < rhs.raw_value);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (raw_value >= rhs.raw_value);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (raw_value <= rhs.raw_value);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (raw_value == rhs.raw_value);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (raw_value != rhs.raw_value);
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
    ++raw_value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++raw_value;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    --raw_value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --raw_value;
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
