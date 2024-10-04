#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Constructor for Dog class " << type << std::endl;	
}

Dog::~Dog() {
	if (this->brain)
		delete this->brain;
	std::cout << "Destructor for Dog class" << type << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	this->brain = new Brain(*copy.brain);
	this->type = "Dog";
	std::cout << "Constructor by copy for Animal class " << type << std::endl;
}

Dog& Dog::operator=(const Dog& assign) {
	if (this != &assign) {
		Animal::operator=(assign);
		delete this->brain;
		this->brain = new Brain(*assign.brain);
		this->type = assign.type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << this->type << ": Wouaf Wouaf" << std::endl;
}

void Dog::setBrain(Brain *brain) {
	if (this->brain)
		delete this->brain;
	this->brain = brain;
}

std::string Dog::getIdea(int i) const {
    if (i >= 0 && i < 100) {
        return brain->ideas[i];
    }
    return "";
}
