#include "Point.hpp"

Point::Point() : _x(), _y() {}

Point::Point(const Fixed fixedX, const Fixed fixedY) : _x(fixedX), _y(fixedY) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point &Point::operator=(const Point &point) {
    if (this->_x != point._x)
        this->_x = point._x;
    if (this->_y != point._y)
        this->_y = point._y;
	return (*this);
}

Point::~Point() {}
