/* --- Fixed.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/7/2024
------------------------------------------ */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
    Fixed(const int nb);
	Fixed(const float nb);
    ~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator = (const Fixed &other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const ;
private:
	int	_fixedPointNumberValue;
	static const int _fracBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif // FIXED_H
