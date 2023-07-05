#include "Point.hpp"

Point::Point() : _x(), _y() {
    std::cout << "Point constructor called" << std::endl;
}

Point::Point(const Fixed fixedX, const Fixed fixedY) : _x(fixedX), _y(fixedY) {
    std::cout << "Point constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {
    std::cout << "Point Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &point) {
    std::cout << "Point Copy assignment operator called" << std::endl;
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

Point::~Point() {
    std::cout << "Point Destructor called" << std::endl;
}

const Fixed Point::getX() const {
    return this->_x;
}

const Fixed Point::getY() const {
    return this->_y;
}
