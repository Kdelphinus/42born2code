#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"

int main() {
	Point p = Point(Fixed(0), Fixed(0));
    Point a = Point(Fixed(-1), Fixed(-1));
    Point b = Point(Fixed(1), Fixed(-1));
    Point c = Point(Fixed(0), Fixed(1));

    std::cout << "bsp: " << bsp(a, b, c, p) << std::endl;
	return 0;
}
