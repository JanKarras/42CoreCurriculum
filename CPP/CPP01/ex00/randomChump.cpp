#include "Zombie.h"

void	randomChump(std::string name) {
	Zombie	zombie;

	zombie.setName(name);
	zombie.announce();
}
