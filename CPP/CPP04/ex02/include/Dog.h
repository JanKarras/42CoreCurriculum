/* --- Dog.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/28/2024
------------------------------------------ */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
public:
	//Constructors
	Dog();
	//Destructors
	~Dog();
	//Copy constructor
	Dog(const Dog &other);
	//copy assigment constructor
	Dog&operator=(const Dog &other);
	//public methods
	void setIdea(std::string idea, int i);
	std::string getIdea(int i);
	//deriveded methods
	void makeSound( void ) const;

private:
	Brain *_brain;
};

#endif // DOG_H
