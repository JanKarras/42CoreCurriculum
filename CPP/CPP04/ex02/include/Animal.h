/* --- Animal.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/28/2024
------------------------------------------ */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
public:
	//Constructors
	Animal();
	Animal(const std::string type);
	//Destructors
	virtual ~Animal();
	//Copy constructor
	Animal(const Animal &other);
	//copy assigment constructor
	Animal&operator=(const Animal &other);
	//public methods
	std::string getType( void ) const;
	//deriveded methods
	virtual void makeSound( void ) const = 0;
protected:
	std::string _type;

};


#endif // ANIMAL_H
