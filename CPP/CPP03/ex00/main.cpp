#include "ClapTrap.h"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << "Testing" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "Deconstructing" << std::endl;
	}
	return (0);
}
