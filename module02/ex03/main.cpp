#include "Point.hpp"

bool bsp(Point a, Point b, Point c, Point point);
void test(const Point &a, const Point &b, const Point &c, const Point &p);

int  main(void)
{
    Point a(0, 0);
    Point b(8, 0);
    Point c(2, 5);
    std::cout << "a" << a << ", "
              << "b" << b << ", "
              << "c" << c << "\n\n";
    test(a, b, c, Point(1, 2.3));
    test(a, b, c, Point(4, 0));
    test(a, b, c, Point(2, 5));
    test(a, b, c, Point(1.9, 4));
    for (float i = 6; i <= 7.9; i += 0.1)
        test(a, b, c, Point(i, 0.2));
    return (0);
}

void test(const Point &a, const Point &b, const Point &c, const Point &p)
{
    std::cout << p << " " << bsp(a, b, c, p) << "\n";
}
