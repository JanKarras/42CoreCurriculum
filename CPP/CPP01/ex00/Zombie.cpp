/* --- Zombie.cpp --- */

/* ------------------------------------------
author: undefined
date: 10/30/2024
------------------------------------------ */

#include "Zombie.h"

Zombie::Zombie() {

}

Zombie::~Zombie() {
    std::cout << name << " is destroyed.\n";
}

std::string Zombie::getName() {
    return name;
}
void	Zombie::setName(std::string& value) {
    name = value;
}

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
