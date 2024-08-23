#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde;
	
	if (N <= 0)
		std::cout << "You need at least 1 Zombie" << std::endl;
	else
	{
	horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].setName(name + std::to_string(i));
		return horde;
	}
	return 0;
}
