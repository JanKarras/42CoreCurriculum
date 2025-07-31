/* --- FragTrap.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/13/2024
------------------------------------------ */

#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap deafult constructor for " << _name << " called\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Deconstructor for " << _name << " called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "ClapTrap constructor for the name " << _name << " called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap assignment operator called\n";
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}


void	FragTrap::highFiveGuys( void ) {
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " can't high give because he has no hitpoints or energy points left\n";
	else
		std::cout << "ScavTrap " << this->_name << " wants to high five someone\n";
}
