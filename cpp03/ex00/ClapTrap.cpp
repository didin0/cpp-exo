#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), HP(10), EP(10) {
	std::cout << name  << ": ClapTrap have spawned" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << name  << ": ClapTrap has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : name(name), HP(10), EP(10) {
	std::cout << name << ": Copy of ClapTrap have spawned" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap assign) {
	if (this != &assign) {
		this->name = assign.getName();
	}
	return *this;
}

std::string ClapTrap::getName() {
	return this->name;
}

void ClapTrap::attack(const std::string& target) {
	if (this->HP <= 0)
		std::cout << this->name << ": is dead, need to repair" << std::endl;
	if (this->EA >= 0) {
		std::cout << this->name << ": attacks " << target << ", causing " << this->AD << " points of damage!" << std::endl;
		this->EA--;
	}
	else
		std::cout << this->name << ": no energy points" << std::endl;
}

void 
