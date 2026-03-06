#include "Fixed.hpp"

using std::cout;

Fixed::Fixed(void) {
    cout << "Default constructor called\n";
    raw_value = 0;
}

Fixed::Fixed(const int value) {
    cout << "Int constructor called\n";
    raw_value = value << fractional_bits;
}

Fixed::Fixed(const float value) {
    cout << "Float constructor called\n";
    raw_value = roundf(value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &copy) {
    cout << "Copy constructor called\n";
    raw_value = copy.raw_value;
}

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
    return (raw_value);
}

void Fixed::setRawBits(int const raw) {
    raw_value = raw;
}

float Fixed::toFloat(void) const {
    return ((float)raw_value / (1 << fractional_bits));
}

int Fixed::toInt(void) const {
    return (raw_value >> fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_point) {
    out << fixed_point.toFloat();
    return (out);
}
