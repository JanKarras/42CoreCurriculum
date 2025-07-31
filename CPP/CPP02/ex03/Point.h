/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:01:17 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:01:23 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
public:
	Point();
	Point(const float x, const float y);
	~Point();
	Point(const Point &other);
	Point &operator= (const Point &other);
	Fixed getX( void ) const;
	Fixed getY( void ) const;
private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_H
