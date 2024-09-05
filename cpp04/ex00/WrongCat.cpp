#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	this->type = "WrongCat";
	std::cout << "Constructor for WrongCat class " << type << std::endl;	
}

WrongCat::~WrongCat() {
	std::cout << "Destructor for WrongCat class" << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	this->type = "WrongCat";
	std::cout << "Constructor by copy for WrongCat class " << type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& assign) {
	if (this != &assign)
		WrongAnimal::operator=(assign);
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << this->type << ": Miaw Miaw" << std::endl;
}

