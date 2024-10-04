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

	for (int i = 0; i < 5; i++)
		std::cout << "Animal type : " << _Animal[i]->getType() << std::endl;

	for (int i = 0; i < 5; i++)
		delete _Animal[i];
	
	std::cout << "\n ------------ TEST --------------" << std::endl;

	Dog dog = Dog();
	Brain *brain = new Brain();
	brain->setIdea("Bonjour");
	brain->setIdea("slt");
	dog.setBrain(brain);
	std::cout << "OG dog idea: " << dog.getIdea(0) << std::endl;
	Dog dog2 = dog;
	std::cout << "CP dog idea: " << dog2.getIdea(1) << std::endl;
	
	return 0;
}
