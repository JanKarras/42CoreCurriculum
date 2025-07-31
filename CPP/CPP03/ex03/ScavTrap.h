/* --- ScavTrap.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/13/2024
------------------------------------------ */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap();
	virtual ~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);

	ScavTrap(std::string name);

	void attack(const std::string& target);
	void guardGate( void );
private:
	bool	_guardMode;
};

#endif // SCAVTRAP_H
