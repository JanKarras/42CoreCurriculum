/* --- HumanB.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/6/2024
------------------------------------------ */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB {
public:
    HumanB(std::string name);
    ~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif // HUMANB_H
