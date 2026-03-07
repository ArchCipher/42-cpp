#include "Point.hpp"

Fixed cross(const Point &ab, const Point &ap);
bool  bsp(Point const a, Point const b, Point const c, Point const point);
void  test(Point &a, Point &b, Point &c, Point p);

/*
    Binary Space Partition

    Vector ab = b - a
    Vector ap = p - a
    Cross product ab * ap = ab.x * ap.y - ab.y * ap.x

    If all cross product result in same sign, point is inside the triangle.
    If any cross product is 0, point is on the triangle
*/
bool  bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed ab_ap = (b - a).crossProduct(point - a);
    Fixed bc_bp = (c - b).crossProduct(point - b);
    Fixed ca_cp = (a - c).crossProduct(point - c);
    if (ab_ap == 0 || bc_bp == 0 || ca_cp == 0)
        return (false);
    bool sign1 = ab_ap > Fixed(0);
    bool sign2 = bc_bp > Fixed(0);
    bool sign3 = ca_cp > Fixed(0);
    return ((sign1 == sign2) && (sign2 == sign3));
}

int main(void)
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

void test(Point &a, Point &b, Point &c, Point p)
{
    std::cout << p << " " << bsp(a, b, c, p) << "\n";
}
