#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    Point a = Point(Fixed(1), Fixed(5));
    Point b = Point(Fixed(5), Fixed(1));
    Point c = Point(Fixed(5), Fixed(5));

    std::cout << std::boolalpha;

    Point p1 = Point(Fixed(4), Fixed(4));
    std::cout <<  "inside of a triangle: " << bsp(a, b, c, p1) << std::endl;

    Point p2 = Point(Fixed(0), Fixed(-1));
    std::cout << "boundary of a triangle: " << bsp(a, b, c, p2) << std::endl;

    Point p3 = Point(Fixed(1), Fixed(0));
    std::cout << "outside of a triangle: " << bsp(a, b, c, p3) << std::endl;

    Point p4 = Point(Fixed(-1), Fixed(1));
    std::cout << "outside of a triangle: " << bsp(a, b, c, p4) << std::endl;

    return 0;
}
