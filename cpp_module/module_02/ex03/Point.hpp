#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const Fixed fixedX, const Fixed fixedY);
        Point(const Point &point);
        Point &operator=(const Point &point);
        ~Point();
};

#endif
