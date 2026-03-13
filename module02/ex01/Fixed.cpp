#include "Fixed.hpp"

using std::cout;

Fixed::~Fixed(void)
{
    cout << "Destructor called\n";
}

Fixed::Fixed(void) : rawValue(0)
{
    cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
    cout << "Int constructor called\n";
    rawValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    cout << "Float constructor called\n";
    rawValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &copy) : rawValue(copy.rawValue)
{
    cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    cout << "Copy assignment operator called\n";
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_point)
{
    out << fixed_point.toFloat();
    return (out);
}
