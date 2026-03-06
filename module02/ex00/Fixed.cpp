#include "Fixed.hpp"

using std::cout;

Fixed::Fixed(void) {
    cout << "Default constructor called\n";
    raw_value = 0;
}

Fixed::Fixed(const Fixed &copy) {
    cout << "Copy constructor called\n";
    raw_value = copy.getRawBits();
}

// optional using initialiser list
// Fixed::Fixed(const Fixed& copy) : raw_value(copy.raw_value)

Fixed &Fixed::operator=(const Fixed &copy) {
    cout << "Copy assignment operator called\n";
    if (&copy != this)
        raw_value = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed(void) {
    cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
    cout << "getRawBits member function called\n";
    return (raw_value);
}

void Fixed::setRawBits(int const raw) {
    cout << "setRawBits member function called\n";
    raw_value = raw;
}
