/* --- HumanA.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/4/2024
------------------------------------------ */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)  {
	return ;
}


HumanA::~HumanA() {
	return ;
}

void HumanA::attack() {
	std::cout << this->_name << " attacks with thier " << this->_weapon.getType() << std::endl;
}
