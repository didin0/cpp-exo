#include "Zombie.hpp"

int main()
{
	Zombie *newbie = newZombie("newbie");
	randomChump("rewbie");
	newbie->announce();
	delete newbie;
	
	return 0;
}

