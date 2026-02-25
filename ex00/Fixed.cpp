#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixed_point(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {

}

Fixed &Fixed::operator=(const Fixed &other) {

}

int Fixed::getRawBits(void) const {

}

void Fixed::setRawBits(int const raw) {

}