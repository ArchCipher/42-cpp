#include "Fixed.hpp"

/*
    Reading:
        [Understanding and Using Floating Point Numbers]
    (https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)
        [Introduction to Floating Number Representation]
    (https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html)

    Floats:

    Total bits = 32
    1 bit sign
    8-bit exponent
    23-bit mantissa (fraction)

    value = (-1)^sign * 1.mantissa * 2^(exponent - 127)
*/

void test();

int  main(void)
{
    Fixed       a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << '\n';
    std::cout << "b is " << b << '\n';
    std::cout << "c is " << c << '\n';
    std::cout << "d is " << d << '\n';
    std::cout << "a is " << a.toInt() << " as integer" << '\n';
    std::cout << "b is " << b.toInt() << " as integer" << '\n';
    std::cout << "c is " << c.toInt() << " as integer" << '\n';
    std::cout << "d is " << d.toInt() << " as integer" << '\n';
    test();
    return 0;
}

#include <iomanip>

void test()
{
    // Precision: 0.1 cannot be represented exactly in floats and fixed point
    // 1/10 in binary is 0.00011001100110011001100110011...
    std::cout << "\n--- Test precision of 0.1 ---\n";
    Fixed const e(0.1f);
    float       f = 0.1;
    std::cout << std::setprecision(20);
    std::cout << "Fixed point is " << e << '\n';
    std::cout << "float is " << f << '\n';

    // Max safe integer ≈ 8,388,607
    // (2^31 - 1) >> 8 or INT_MAX >> fractional_bits
    std::cout
        << "\n--- Test for overflow in Float point (Max ≈ 8,388,607) ---\n";
    Fixed const g(10000000);
    std::cout << "Float point (10,000,000) is " << g << '\n';

    std::cout << "\n--- Addition of 0.1 + 0.2 ---\n";
    float x = 0.1f + 0.2f;
    std::cout << "float  is " << x << "\n";
    Fixed y(0.1f);
    Fixed z(0.2f);
    std::cout << "Fixed point is " << y.toFloat() + z.toFloat() << "\n\n";
}
