#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Constructor for Dog class " << type << std::endl;	
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Destructor for Dog class" << type << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	this->type = "Dog";
	std::cout << "Constructor by copy for Animal class " << type << std::endl;
}

Dog& Dog::operator=(const Dog& assign) {
	if (this != &assign)
		Animal::operator=(assign);
	return *this;
}

void Dog::makeSound() const {
	std::cout << this->type << ": Wouaf Wouaf" << std::endl;
}
