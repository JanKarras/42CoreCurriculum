/* --- Dog.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/28/2024
------------------------------------------ */

#include "../include/Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog() {
	std::cout << "Dog deconstructor for type " << this->_type << " called\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assigment constructor called\n";
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "bark\n";
}

