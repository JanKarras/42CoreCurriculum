/* --- Cat.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/28/2024
------------------------------------------ */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "Brain.h"

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
	void setIdea(std::string idea, int i);
	std::string getIdea(int i);
	//deriveded methods
	void makeSound( void ) const;
private:
	Brain *_brain;
};

#endif // CAT_H
