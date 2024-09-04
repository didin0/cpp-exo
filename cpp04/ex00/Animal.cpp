#include "Animal.hpp"

Animal::Animal(std::string type) : type(type) {
	std::cout << "Constructor for Animal class " << type << std::endl;
}

Animal::Animal() {
	this->type = "Default"
	std::cout << "Constructor for Animal class " << type << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor for Animal class " << type << std::endl;
}

Animal::Animal(const Animal& copy) type(type) {
	std::cout << "Constructor by copy for Animal " << type << std::endl;
}

Animal& Animal::operator=(const Animal& assign) {
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << type << ": ???????" << std::endl;
}
