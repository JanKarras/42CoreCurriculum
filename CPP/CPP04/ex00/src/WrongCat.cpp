/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:07:59 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:08:00 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Cat default constructor called\n";
}

WrongCat::~WrongCat() {
	std::cout << "Cat deconstructor for type " << this->_type << " called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Cat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "Cat copy assigment constructor called\n";
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound( void ) const {
	std::cout << "wrong purr\n";
}
