/* --- Weapon.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/4/2024
------------------------------------------ */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {
public:
    Weapon();
	Weapon(std::string WeaponType);
    ~Weapon();

    const std::string &getType() const;
    void setType(const std::string& value);

private:
	std::string type;
};

#endif
