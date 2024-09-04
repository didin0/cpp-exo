#include "FlagTrap.hpp"

int main() {
	FlagTrap bob = FlagTrap("bob");
	FlagTrap *anis = new FlagTrap(bob); 
	delete anis;
	bob.attack("random");
	bob.highFivesGuys();
	bob.takeDamage(7);
	bob.beRepaired(1);

	return 0;
}
