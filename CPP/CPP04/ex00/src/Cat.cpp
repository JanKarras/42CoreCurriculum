/* --- Cat.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/28/2024
------------------------------------------ */

#include "../include/Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat() {
	std::cout << "Cat deconstructor for type " << this->_type << " called\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assigment constructor called\n";
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "purr\n";
}
