#include "Fixed.hpp"

using std::cout;

Fixed::~Fixed(void)
{
    cout << "Destructor called\n";
}

// using initialiser list
Fixed::Fixed(void) : rawValue(0)
{
    cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
    cout << "Copy constructor called\n";
    rawValue = copy.getRawBits();
}

// optional using initialiser list
// Fixed::Fixed(const Fixed& copy) : raw_value(copy.raw_value)

Fixed &Fixed::operator=(const Fixed &copy)
{
    cout << "Copy assignment operator called\n";
    if (&copy != this)
        rawValue = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    cout << "getRawBits member function called\n";
    return (rawValue);
}

void Fixed::setRawBits(int const raw)
{
    cout << "setRawBits member function called\n";
    rawValue = raw;
}
