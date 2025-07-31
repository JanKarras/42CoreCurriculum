/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:12:55 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:12:56 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called\n";
	this->_brain = new Brain();
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog deconstructor for type " << this->_type << " called\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called\n";
	this->_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assigment constructor called\n";
	if (this != &other) {
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "bark\n";
}

void Dog::setIdea(std::string idea, int i) {
	this->_brain->setIdea(idea, i);
}

std::string Dog::getIdea(int i) {
	std::string s = this->_brain->getIdea(i);
	return (s);
}
