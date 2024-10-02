#include "Fixed.hpp"

Fixed::Fixed() : _num(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _num(fixed.getRawBits()) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_num = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num) : _num(num << this->_fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _num(roundf(num * (1 << this->_fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_num;
}

void Fixed::setRawBits(const int raw) {
    this->_num = raw;
}

int Fixed::toInt(void) const {
    return this->_num >> this->_fractionalBits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_num) / (1 << this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    return out << fixed.toFloat();
}