#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), HP(10), EP(10), AD(5) {
	std::cout << name  << ": ClapTrap have spawned" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << name  << ": ClapTrap has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : name(copy.name), HP(10), EP(10) {
	std::cout << name << ": Copy of ClapTrap have spawned" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& assign) {
	if (this != &assign) {
		this->name = assign.getName();
		this->HP = assign.HP;
		this->EP = assign.EP;
		this->AD = assign.AD;
	}
	return *this;
}

std::string ClapTrap::getName() const {
	return this->name;
}

void ClapTrap::attack(const std::string& target) {
	if (this->HP <= 0)
		std::cout << this->name << ": is dead, need to repair" << std::endl;
	if (this->EP > 0) {
		std::cout << this->name << ": attacks " << target << " with his power of " << this->AD << "AD" << std::endl;
		this->EP--;
	}
	else
		std::cout << this->name << ": no energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amout) {
	if (this->HP <= 0)
		std::cout << this->name << ": alrdy died" << std::endl;
	else {
		if (amout > HP)
			this->HP = this->HP - this->HP;
		else
			this->HP = this->HP - amout;
		std::cout << this->name << ": took " << amout << " damage, now have " << this->HP << "/100HP" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amout) {
	if (this->EP > 0) {
		if (amout > this->HP)
			this->HP = 10;
		else
			this->HP += amout;
		std::cout << this->name << ": healed " << amout << "HP, now have " << this->HP << "/100HP" << std::endl;
	}
	else
		std::cout << this->name << ": no energy points" << std::endl;
}
