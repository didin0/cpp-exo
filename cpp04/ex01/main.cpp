#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>

int main ( void )
{
	Animal* _Animal[5];

	for (int i = 0; i < 5; i++)
	{
		if (!(i % 2))
			_Animal[i] = new Cat();
        else
			_Animal[i] = new Dog();
	}

	Dog dog = Dog();
	Dog dog2 = dog;

	for (int i = 0; i < 5; i++)
		std::cout << "Animal type : " << _Animal[i]->getType() << std::endl;

	for (int i = 0; i < 5; i++)
		delete _Animal[i];

	system("leaks brain");
	return 0;
}
