#include "Zombie.hpp"

int main()
{
	int N = 0;
	Zombie *horbie = zombieHorde(N, "horbie");
	for (int i = 0; i < N; i++)
		horbie[i].announce();
	delete[] horbie;
	//system("leaks Zombie");	
	return 0;
}

