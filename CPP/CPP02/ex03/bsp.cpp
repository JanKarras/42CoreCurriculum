/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:59:23 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:59:25 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

bool	check_side(Point const p1, Point const p2, Point const point, bool check_below) {
	const Fixed epsilon = Fixed(0.00390625f);
	Fixed	m;
	Fixed	b;
	Fixed	y_func;
	if (p1.getX() == p2.getX()) {
		if (check_below) {
			return point.getY() <= y_func + epsilon;
		} else {
			return point.getY() >= y_func - epsilon;
		}
	}
	m = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
	b = p1.getY() - m * p1.getX();
	y_func = m * point.getX() + b;
	if (check_below) {
		return point.getY() <= y_func + epsilon;
	} else {
		return point.getY() >= y_func - epsilon;
	}
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	if (!check_side(a, c,  point, true)) {
		return (false);
	} else if (!check_side(a, b, point, false)) {
		return (false);
	} else if (!check_side(b, c, point, true)) {
		return (false);
	} else {
		return (true);
	}
}
