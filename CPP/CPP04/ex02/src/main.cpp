/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:13:00 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:13:24 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.h"
#include "../include/Cat.h"

int main() {
	const size_t arraySize = 10;
	const size_t halfSize = arraySize / 2;
	const Animal* animals[arraySize];
	
	for (size_t i = 0; i < halfSize; ++i) {
		animals[i] = new Dog();
	}
	
	for (size_t i = halfSize; i < arraySize; ++i) {
		animals[i] = new Cat();
	}
	
	for (size_t i = 0; i < arraySize; ++i) {
		animals[i]->makeSound();
	}
	
	for (size_t i = 0; i < arraySize; ++i) {
		delete animals[i];
	}
	
	Dog dog1;
	dog1.setIdea("search for food", 0);
	dog1.setIdea("search for pee", 1);
	dog1.setIdea("search for bone", 2);
	Dog dog2 = dog1;
	
	std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;
	std::cout << "dog1 idea: " << dog1.getIdea(1) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(1) << std::endl;
	std::cout << "dog1 idea: " << dog1.getIdea(2) << std::endl;
	std::cout << "dog2 idea: " << dog2.getIdea(2) << std::endl;
	
	dog1.setIdea("Woof", 0);
	std::cout << "dog1 idea after modification: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2 idea after dog1 modification: " << dog2.getIdea(0) << std::endl;
	
	return 0;
}
