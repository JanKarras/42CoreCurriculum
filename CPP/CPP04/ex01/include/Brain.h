/* --- Brain.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/28/2024
------------------------------------------ */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain {
public:
	//Constructors
	Brain();
	//Destructors
	~Brain();
	//Copy constructor
	Brain(const Brain &other);
	//copy assigment constructor
	Brain&operator=(const Brain &other);
	//public methods
	void setIdea(std::string idea, int i);
	std::string getIdea(int i);
private:
	std::string _ideas[100];
};

#endif // BRAIN_H
