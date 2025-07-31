#include "Weapon.h"
#include "HumanA.h"
#include "HumanB.h"

int	main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB rene("Rene");
		rene.attack();
		rene.setWeapon(club);
		rene.attack();
		club.setType("some other type of club");
		rene.attack();
	}
	return (0);
}
