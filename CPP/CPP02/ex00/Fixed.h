/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:56:39 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 12:56:40 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator = (const Fixed &other);
	int getRawBits ( void ) const;
	void setRawBits( int const raw );
private:
	int	_fixedPointNumberValue;
	static const int _fracBits = 8;
};

#endif // FIXED_H
