#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    Point a = Point(Fixed(-1), Fixed(-1));
    Point b = Point(Fixed(1), Fixed(-1));
    Point c = Point(Fixed(0), Fixed(1));

    Point p1 = Point(Fixed(0), Fixed(0));
    std::cout << "inside of a triangle: " << bsp(a, b, c, p1) << std::endl;

    Point p2 = Point(Fixed(0), Fixed(-1));
    std::cout << "boundary of a triangle: " << bsp(a, b, c, p2) << std::endl;

    Point p3 = Point(Fixed(1), Fixed(0));
    std::cout << "outside of a triangle: " << bsp(a, b, c, p3) << std::endl;
	return 0;
}
