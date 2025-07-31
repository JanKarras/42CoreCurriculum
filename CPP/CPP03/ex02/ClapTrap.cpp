/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:03:14 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:03:16 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap(): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Deconstructor for " << _name << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called\n";
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap constructor for the name " << _name << " called\n";
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " points of damage!\n";
		this->_energyPoints--;
	} else if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left\n";
	} else if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is not able to attack " << target << ", because he has no hit points left\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
	} else if (this->_hitPoints > 0) {
		this->_hitPoints = 0;
	} else {
		std::cout << "ClapTrap " << this->_name << "is already broken. Don't harm him anymore!\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " was attackt and lost " << amount << " hit points, he now has " << this->_hitPoints << " hit points\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0 && this->_hitPoints + amount <= 100) {
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself and gaind " << amount << " hit points, he has now " << this->_hitPoints << " hit points\n";
		this->_energyPoints--;
	} else if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is not able to repair itself, because he has no energy points left\n";
	} else if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is not able to repair itself, because he has no hit points left\n";
	} else {
		std::cout << "ClapTrap " << this->_name << " can't be repaired to have more than 100 hitpoints\n";
	}
}
