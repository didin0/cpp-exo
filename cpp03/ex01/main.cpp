#include "ScravTrap.hpp"

int main() {
	ScravTrap bob = ScravTrap("bob");
	bob.attack("random");
	bob.guardGate();
	bob.takeDamage(7);
	bob.beRepaired(1);
	return 0;
}
