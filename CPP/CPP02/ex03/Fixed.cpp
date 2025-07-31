/* --- Fixed.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/7/2024
------------------------------------------ */

#include "Fixed.h"

Fixed::Fixed() : _fixedPointNumberValue(0) {
    //std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nb) {
	//std::cout << "Int constructor called\n";
	this->_fixedPointNumberValue = nb << this->_fracBits;
}

Fixed::Fixed(const float nb) {
	//std::cout << "Float constructor called\n";
	this->_fixedPointNumberValue = static_cast<int>(roundf(nb * (1 << _fracBits)));
}

Fixed::~Fixed() {
    //std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) : _fixedPointNumberValue(other._fixedPointNumberValue) {
	//std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
	//std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->_fixedPointNumberValue = other.getRawBits();
	}
	return *this;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumberValue = this->_fixedPointNumberValue + other._fixedPointNumberValue;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumberValue = this->_fixedPointNumberValue - other._fixedPointNumberValue;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumberValue = (this->_fixedPointNumberValue * other._fixedPointNumberValue) >> _fracBits;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result._fixedPointNumberValue = (this->_fixedPointNumberValue << _fracBits) / other._fixedPointNumberValue;
	return result;
}

bool Fixed::operator>(const Fixed &other) {
	return this->_fixedPointNumberValue > other._fixedPointNumberValue;
}

bool Fixed::operator<(const Fixed &other) {
	return this->_fixedPointNumberValue < other._fixedPointNumberValue;
}

bool Fixed::operator>=(const Fixed &other) {
	return this->_fixedPointNumberValue >= other._fixedPointNumberValue;
}

bool Fixed::operator<=(const Fixed &other) {
	return this->_fixedPointNumberValue <= other._fixedPointNumberValue;
}

bool Fixed::operator==(const Fixed &other) {
	return this->_fixedPointNumberValue == other._fixedPointNumberValue;
}

bool Fixed::operator!=(const Fixed &other) {
	return this->_fixedPointNumberValue != other._fixedPointNumberValue;
}

Fixed &Fixed::operator++( void ) {
	++_fixedPointNumberValue;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed result(*this);
	++(*this);
	return (result);
}

Fixed &Fixed::operator--( void ) {
	--_fixedPointNumberValue;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	Fixed result(*this);
	--(*this);
	return (result);
}

Fixed Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1._fixedPointNumberValue > f2._fixedPointNumberValue)
		return (f2);
	else
		return (f1);
}

const Fixed Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1._fixedPointNumberValue > f2._fixedPointNumberValue)
		return (f2);
	else
		return (f1);
}

Fixed Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1._fixedPointNumberValue < f2._fixedPointNumberValue)
		return (f2);
	else
		return (f1);
}

const Fixed Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1._fixedPointNumberValue < f2._fixedPointNumberValue)
		return (f2);
	else
		return (f1);
}

int Fixed::getRawBits( void ) const {
	return this->_fixedPointNumberValue;
}

void Fixed::setRawBits( int const raw) {
	this->_fixedPointNumberValue = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->_fixedPointNumberValue) / (1 << _fracBits);
}

int Fixed::toInt( void ) const {
	return this->_fixedPointNumberValue >> this->_fracBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();  // Output the fixed-point value as a float
	return out;
}
