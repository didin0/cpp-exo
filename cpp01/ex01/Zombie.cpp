#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::Zombie() {
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << "Destructor for " << this->name << std::endl;
	return;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
