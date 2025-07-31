/* --- Point.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/8/2024
------------------------------------------ */

#include "Point.h"

Point::Point() : _x(0), _y(0) {
    // Constructor
}

Point::~Point() {
    // Destructor
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    // Constructor
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {

}

Point &Point::operator= (const Point &other) {
	other.getX();
	return (*this);
}

Fixed Point::getX( void ) const {
	return _x;
}

Fixed Point::getY( void ) const {
	return _y;
}
