/* --- Cat.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/28/2024
------------------------------------------ */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat  : public Animal {
public:
	//Constructors
	Cat();
	//Destructors
	~Cat();
	//Copy constructor
	Cat(const Cat &other);
	//copy assigment constructor
	Cat&operator=(const Cat &other);
	//public methods

	//deriveded methods
	void makeSound( void ) const;
private:

};

#endif // CAT_H
