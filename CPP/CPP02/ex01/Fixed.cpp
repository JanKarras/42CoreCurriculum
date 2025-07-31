/* --- Fixed.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/7/2024
------------------------------------------ */

#include "Fixed.h"

Fixed::Fixed() : _fixedPointNumberValue(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nb) : _fixedPointNumberValue() {
	std::cout << "Int constructor called\n";
	this->_fixedPointNumberValue = nb << this->_fracBits;
}

Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called\n";
	this->_fixedPointNumberValue = static_cast<int>(roundf(nb * (1 << _fracBits)));
	// Rechnung: 3.14159 * 256 = 804.2496
	// roundf: 804.2496 → 804
	// Ergebnis: _fixedPointNumberValue = 804
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

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->_fixedPointNumberValue) / (1 << _fracBits);
	//Rechnung 804 / 256 = 3.140625
	//mit fracBits erhoehung wird das ergebnis genaer, aber verbraucht auch mehr speiecher.
}

int Fixed::toInt( void ) const {
	return this->_fixedPointNumberValue >> this->_fracBits;
	//Rechnung 804 / 256 = 3.140625
	//retun 3;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();  // Output the fixed-point value as a float
	return out;
}
