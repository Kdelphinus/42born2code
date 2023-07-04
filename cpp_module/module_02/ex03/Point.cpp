#include "Point.hpp"

Point::Point() : _x(), _y() {}

Point::Point(const Fixed fixedX, const Fixed fixedY) : _x(fixedX), _y(fixedY) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point &Point::operator=(const Point &point) {
    if (this->_x != point.getX()) {
        Fixed &tmpX = const_cast<Fixed &>(this->_x);
        tmpX = point.getX();
    }
    if (this->_y != point.getY()) {
        Fixed &tmpY = const_cast<Fixed &>(this->_y);
        tmpY = point.getY();
    }
    return *this;
}

Point::~Point() {}

const Fixed Point::getX() const {
    return this->_x;
}

const Fixed Point::getY() const {
    return this->_y;
}
