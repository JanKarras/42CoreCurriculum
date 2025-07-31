/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:01:04 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:01:11 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point() : _x(0), _y(0) {
}

Point::~Point() {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
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
