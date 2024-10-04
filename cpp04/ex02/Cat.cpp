#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Constructor for Cat class " << type << std::endl;	
}

Cat::~Cat() {
	if (this->brain)
		delete this->brain;
	std::cout << "Destructor for Cat class" << type << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	this->brain = new Brain(*copy.brain);
	this->type = "Cat";
	std::cout << "Constructor by copy for Animal class " << type << std::endl;
}

Cat& Cat::operator=(const Cat& assign) {
	if (this != &assign) {
		Animal::operator=(assign);
		delete this->brain;
		this->brain = new Brain(*assign.brain);
		this->type = assign.type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << this->type << ": Wouaf Wouaf" << std::endl;
}

void Cat::setBrain(Brain *brain) {
	if (this->brain)
		delete this->brain;
	this->brain = brain;
}

std::string Cat::getIdea(int i) const {
    if (i >= 0 && i < 100) {
        return brain->ideas[i];
    }
    return "";
}

