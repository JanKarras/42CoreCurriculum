/* --- ScavTrap.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/13/2024
------------------------------------------ */

#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardMode = false;
	std::cout << "ScavTrap deafult constructor for " << _name << " called\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Deconstructor for " << _name << " called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	this->_guardMode = other._guardMode;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardMode = false;
	std::cout << "ScavTrap Constructor with name " << name << " called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap assignment operator called\n";
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " points of damage!\n";
		this->_energyPoints--;
	} else if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left\n";
	} else if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is not able to attack " << target << ", because he has no hit points left\n";
	}
}

void ScavTrap::guardGate( void ) {
	if (this->_guardMode == false) {
		this->_guardMode = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate\n";
	} else {
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate\n";
	}
}

