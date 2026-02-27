#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixed_point(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : fixed_point(integer << fractional_bits){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floating_point) : fixed_point(roundf(floating_point * (float)(1 << fractional_bits))){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object) {
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed &Fixed::operator=(const Fixed &object) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &object)
        this->fixed_point = object.fixed_point;
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw) {
    this->fixed_point = raw;
}

float Fixed::toFloat( void ) const {
    return this->fixed_point / (float)(1 << fractional_bits);
}

int Fixed::toInt( void ) const {
    return this->fixed_point >> fractional_bits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->fixed_point > other.fixed_point;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->fixed_point < other.fixed_point;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->fixed_point >= other.fixed_point;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->fixed_point <= other.fixed_point;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->fixed_point == other.fixed_point;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->fixed_point != other.fixed_point;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.fixed_point = this->fixed_point + other.fixed_point;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.fixed_point = this->fixed_point - other.fixed_point;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {

}

Fixed Fixed::operator/(const Fixed &other) const {

}

Fixed &Fixed::operator++() {
    this->fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->fixed_point++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->fixed_point--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a.fixed_point < b.fixed_point)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.fixed_point < b.fixed_point)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a.fixed_point > b.fixed_point)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.fixed_point > b.fixed_point)
        return a;
    return b;
}
