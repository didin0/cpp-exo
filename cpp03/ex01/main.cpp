#include "ScravTrap.hpp"

int main() {
	ClapTrap bob = ScravTrap("bob");
	ClapTrap obo = ClapTrap("obo");
	bob.attack("obo");
	obo.takeDamage(10);
	obo.beRepaired(999);
	return 0;
}
