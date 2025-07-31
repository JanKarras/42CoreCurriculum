/* --- Weapon.cpp --- */

/* ------------------------------------------
author: undefined
date: 11/4/2024
------------------------------------------ */

#include "Weapon.h"

Weapon::Weapon() {
    return ;
}

Weapon::Weapon(std::string WeaponType) : type(WeaponType) {
	return ;
}

Weapon::~Weapon() {
    return ;
}

const std::string &Weapon::getType() const{
    return this->type;
}
void Weapon::setType(const std::string& value) {
    type = value;
}
