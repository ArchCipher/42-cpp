#include "Fixed.hpp"

/*
Reading:
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html

The Orthodox Canonical Form in C++ involves defining
5 special member functions for a class.

1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor
4. Assignment Operator
5. Destructor
*/

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << '\n';
    std::cout << b.getRawBits() << '\n';
    std::cout << c.getRawBits() << '\n';
    return (0);
}
