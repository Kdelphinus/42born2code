#include "Fixed.hpp"

Fixed::Fixed() : _num(0) {}

Fixed::Fixed(const Fixed &fixed) : _num(fixed._num) {}

Fixed &Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed)
        this->_num = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int num) : _num(num << this->_fractionalBits) {}

Fixed::Fixed(const float num) : _num(roundf(num * (1 << this->_fractionalBits))) {}

int Fixed::getRawBits() const {
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

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    int mod = 1 << this->_fractionalBits;
    int fixedMod = 1 << fixed._fractionalBits;
    return Fixed((static_cast<float>(this->_num) / mod) * (static_cast<float>(fixed._num) / fixedMod));
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    int mod = 1 << this->_fractionalBits;
    int fixedMod = 1 << fixed._fractionalBits;
    return Fixed((static_cast<float>(this->_num) / mod) / (static_cast<float>(fixed._num) / fixedMod));
}

Fixed Fixed::operator++(void) {
    this->_num++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->_num++;
    return tmp;
}

Fixed Fixed::operator--() {
    this->_num--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->_num--;
    return tmp;
}

bool Fixed::operator>(const Fixed &fixed) const {
    if (this->toFloat() > fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &fixed) const {
    if (this->toFloat() < fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &fixed) const {
    if (this->toFloat() >= fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &fixed) const {
    if (this->toFloat() <= fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &fixed) const {
    if (this->toFloat() == fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &fixed) const {
    if (this->toFloat() != fixed.toFloat())
        return true;
    return false;
}

const Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
    if (fixed1.toFloat() > fixed2.toFloat())
        return fixed1;
    return fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
    if (fixed1.toFloat() > fixed2.toFloat())
        return fixed1;
    return fixed2;
}

const Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
    if (fixed1.toFloat() < fixed2.toFloat())
        return fixed1;
    return fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
    if (fixed1.toFloat() < fixed2.toFloat())
        return fixed1;
    return fixed2;
}