/* --- Fixed.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/7/2024
------------------------------------------ */

#include "Fixed.h"

#include <string>
#include <iostream>

Fixed::Fixed() : _fixedPointNumberValue(0) {
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) : _fixedPointNumberValue(other._fixedPointNumberValue) {
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->_fixedPointNumberValue = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return this->_fixedPointNumberValue;
}

void Fixed::setRawBits( int const raw) {
	this->_fixedPointNumberValue = raw;
}
