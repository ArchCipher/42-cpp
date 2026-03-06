#include "Fixed.hpp"

void test();

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    // test();
    return (0);
}

/*
Reading:
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html


Floats:

Total bits = 32
1 bit sign
8-bit exponent
23-bit mantissa (fraction)

value = (-1)^sign * 1.mantissa * 2^(exponent - 127)
*/

void test()
{
    std::cout << "\n";
    Fixed const a( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const b( Fixed( 5.05f ) - Fixed( 2 ) );
    Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
    Fixed const d( Fixed( 5.05f ) / Fixed( 0 ) );
    Fixed const e( Fixed( 0 ) / Fixed( 2 ) );
    Fixed const f( Fixed( 0 ) / Fixed( 0 ) );
    std::cout << "- Addition (5.05 + 2)\n";
    std::cout << a << std::endl;
    std::cout << "- Subtraction (5.05 - 2)\n";
    std::cout <<  b << std::endl;
    std::cout << "- Subtraction (2 - 5.05)\n";
    Fixed const rev( Fixed( 2 ) - Fixed( 5.05f ) );
    std::cout << rev << std::endl;
    std::cout << "- Division (5.05 / 2)\n";
    std::cout << c << std::endl;
    std::cout << "- Division (5.05 / 0)\n";
    std::cout << d << std::endl;
    std::cout << "- Division (0 / 2)\n";
    std::cout << e << std::endl;
    std::cout << "- Division (0 / 0)\n";
    std::cout << f << std::endl;
}
