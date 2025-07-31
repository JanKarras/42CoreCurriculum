/* --- HumanA.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/4/2024
------------------------------------------ */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
public:
	HumanA(std::string name, Weapon &_weapon);
    ~HumanA();
	void	attack();
private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif // HUMANA_H
