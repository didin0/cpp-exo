#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->type = "Cat";
	std::cout << "Constructor for Cat class " << type << std::endl;	
}

Cat::~Cat() {
	std::cout << "Destructor for Cat class" << type << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	this->type = "Cat";
	std::cout << "Constructor by copy for Cat class " << type << std::endl;
}

Cat& Cat::operator=(const Cat& assign) {
	if (this != &assign)
		Animal::operator=(assign);
	return *this;
}

void Cat::makeSound() const {
	std::cout << this->type << ": Miaw Miaw" << std::endl;
}

