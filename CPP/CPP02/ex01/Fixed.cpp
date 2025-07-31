/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:57:08 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:57:24 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

int Fixed::toInt( void ) const {
	return this->_fixedPointNumberValue >> this->_fracBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return out;
}
