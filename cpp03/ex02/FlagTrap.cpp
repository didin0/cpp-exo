#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name) : ClapTrap(name) {
	this->HP = 100;
	this->EP = 50;
	this->AD = 30;
	std::cout << name << ": FlagTrap have spawned" << std::endl;
}

FlagTrap::~FlagTrap() {
	std::cout << name << ": FlagTrap has been destroyed" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& copy) : ClapTrap(copy){
	this->HP = 100;
	this->EP = 50;
	this->AD = 30;
	this->name = copy.name;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& assign) {
	if (this != &assign)
		ClapTrap::operator=(assign);
	return *this;
}


void FlagTrap::highFivesGuys() {
	if (this->HP)
		std::cout << this->name << ": positive high fives request" << std::endl;
	else
		std::cout << this->name << ": is DEAD............." << std::endl;
}

