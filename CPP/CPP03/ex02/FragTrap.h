/* --- FragTrap.h --- */

/* ------------------------------------------
Author: undefined
Date: 11/13/2024
------------------------------------------ */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	virtual ~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);

	FragTrap(std::string name);

	void highFiveGuys( void );
};

#endif // FRAGTRAP_H
