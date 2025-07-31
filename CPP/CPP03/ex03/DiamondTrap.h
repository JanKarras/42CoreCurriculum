/* --- DiamondTrap.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/14/2024
------------------------------------------ */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap :  public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	virtual ~DiamondTrap();
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);

	DiamondTrap(std::string name);

	void whoAmI( void );
	void attack(const std::string& target);
private:
	std::string	_name;
};

#endif // DIAMONDTRAP_H
