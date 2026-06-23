#include "whatever.hpp"
#include <iostream>
#include <string>

void test_single_const()
{
    const int x = 1;
    int       y = 2;
    std::cout << "----------------\n"
              << "const int x = " << x << ", int y = " << y << '\n'
              << "min( x, y ) = " << ::min(x, y) << '\n'
              << "max( x, y ) = " << ::max(x, y) << '\n';
}

// NOLINTNEXTLINE(bugprone-exception-escape)
int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "min( a, b ) = " << ::min(a, b) << '\n';
    std::cout << "max( a, b ) = " << ::max(a, b) << '\n';
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << '\n';
    std::cout << "min( c, d ) = " << ::min(c, d) << '\n';
    std::cout << "max( c, d ) = " << ::max(c, d) << '\n';
    test_single_const();
    return 0;
}
