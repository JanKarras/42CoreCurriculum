/* --- Cat.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/28/2024
------------------------------------------ */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat  : public WrongAnimal {
public:
	//Constructors
	WrongCat();
	//Destructors
	~WrongCat();
	//Copy constructor
	WrongCat(const WrongCat &other);
	//copy assigment constructor
	WrongCat&operator=(const WrongCat &other);
	//public methods

	//deriveded methods
	void makeSound( void ) const;
private:

};

#endif // WRONGCAT_H
