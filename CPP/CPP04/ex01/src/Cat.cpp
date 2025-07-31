/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:10:11 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:10:13 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called\n";
	this->_brain = new Brain();
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat deconstructor for type " << this->_type << " called\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called\n";
	this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assigment constructor called\n";
	if (this != &other) {
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "purr\n";
}

void Cat::setIdea(std::string idea, int i) {
	this->_brain->setIdea(idea, i);
}

std::string Cat::getIdea(int i) {
	std::string s = this->_brain->getIdea(i);
	return (s);
}
