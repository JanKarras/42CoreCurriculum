/* --- Brain.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/28/2024
------------------------------------------ */

#include "../include/Brain.h"

Brain::Brain() {
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain() {
	std::cout << "Brain deconstructor called\n";
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called\n";
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assigment constructor called\n";
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

void Brain::setIdea(std::string idea, int index) {
	if (index >= 100) {
		std::cout << "Index to big. Range 0 - 99\n";
	} else {
		this->_ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) {
	if (index >= 100) {
		std::cout << "Index to big. Range 0 - 99\n";
		return ("");
	} else {
		return (this->_ideas[index]);
	}
}
