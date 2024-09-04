#include "ScravTrap.hpp"

ScravTrap::ScravTrap(std::string name) : ClapTrap(name) {
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	std::cout << name << ": ScravTrap have spawned" << std::endl;
}

ScravTrap::~ScravTrap() {
	std::cout << name << ": ScravTrap has been destroyed" << std::endl;
}

ScravTrap::ScravTrap(const ScravTrap& copy) : ClapTrap(copy){
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	this->name = copy.name;
}

ScravTrap& ScravTrap::operator=(const ScravTrap& assign) {
	if (this != &assign)
		ClapTrap::operator=(assign);
	return *this;
}

void ScravTrap::attack(const std::string& target) {
	if (this->HP <= 0)
		std::cout << "FROM SCRAVTRAP " << this->name << ": is dead, need to repair" << std::endl;
	if (this->EP > 0) {
		std::cout << "FROM SCRAVTRAP " << this->name << ": attacks " << target << " with his power of " << this->AD << "AD" << std::endl;
		this->EP--;
	}
	else
		std::cout << "FROM SCRVTRAP " << this->name << ": no energy points" << std::endl;
}

void ScravTrap::guardGate() {
	if (this->HP)
		std::cout << this->name << ": is now in Gate keeper mode" << std::endl;
	else
		std::cout << this->name << ": IS DEAD........." << std::endl;
}
