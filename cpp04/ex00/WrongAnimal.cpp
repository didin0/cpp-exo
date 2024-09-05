#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "Constructor for WrongAnimal class " << type << std::endl;
}

WrongAnimal::WrongAnimal() {
	this->type = "Default";
	std::cout << "Constructor for WrongAnimal class " << type << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor for WrongAnimal class " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type) {
	std::cout << "Constructor by copy for WrongAnimal " << type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign) {
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << type << ": ???????" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
