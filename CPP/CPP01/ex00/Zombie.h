/* --- Zombie.h --- */

/* ------------------------------------------
Author: undefined
Date: 10/30/2024
------------------------------------------ */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
public:
    Zombie();
    ~Zombie();

	void	announce(void);

    std::string getName();
    void setName(std::string& value);
private:
	std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif // ZOMBIE_H
