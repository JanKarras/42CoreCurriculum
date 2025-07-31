/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:13:35 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:13:37 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.h"

WrongAnimal::WrongAnimal() : _type("default") {
	std::cout << "wrong animal default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
	std::cout << "wrong animal constructor with type " << type << " called\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "wrong animal deconstructor for type " << this->_type << " called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "wrong animal copy constructor called\n";
	this->_type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "wrong animal copy assigment constructor called\n";
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "wrong default sounds\n";
}

std::string WrongAnimal::getType( void ) const {
	return _type;
}
