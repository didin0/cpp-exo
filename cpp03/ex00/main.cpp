#include "ClapTrap.hpp"

int main() {
	ClapTrap bob = ClapTrap("bob");
	ClapTrap obo = ClapTrap("obo");
	bob.attack("obo");
	obo.takeDamage(10);
	obo.beRepaired(999);
	return 0;
}
