/* --- Animal.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/28/2024
------------------------------------------ */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal {
public:
	//Constructors
	WrongAnimal();
	WrongAnimal(const std::string type);
	//Destructors
	~WrongAnimal();
	//Copy constructor
	WrongAnimal(const WrongAnimal &other);
	//copy assigment constructor
	WrongAnimal&operator=(const WrongAnimal &other);
	//public methods
	std::string getType( void ) const;
	//deriveded methods
	void makeSound( void ) const;
protected:
	std::string _type;

};


#endif // WRONGANIMAL_H
