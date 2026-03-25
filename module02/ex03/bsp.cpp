#include "Point.hpp"

/*
    Binary Space Partition

    Vector ab = b - a
    Vector ap = p - a
    Cross product ab * ap = ab.x * ap.y - ab.y * ap.x

    If all cross product result in same sign, point is inside the triangle.
    If any cross product is 0, point is on the triangle
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
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
