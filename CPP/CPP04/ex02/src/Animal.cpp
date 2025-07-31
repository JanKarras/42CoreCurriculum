/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:12:41 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:12:42 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.h"

Animal::Animal() : _type("default") {
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string type) : _type(type) {
	std::cout << "Animal constructor with type " << type << " called\n";
}

Animal::~Animal() {
	std::cout << "Animal deconstructor for type " << this->_type << " called\n";
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called\n";
	this->_type = other._type;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assigment constructor called\n";
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

void Animal::makeSound( void ) const {
	std::cout << "default sounds\n";
}

std::string Animal::getType( void ) const {
	return _type;
}
