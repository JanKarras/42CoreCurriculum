/* --- Fixed.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/7/2024
------------------------------------------ */

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
