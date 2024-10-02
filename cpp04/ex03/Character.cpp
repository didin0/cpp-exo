#include "Character.hpp"

Character::Character(std::string const &name) : name(name) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

Character::Character(const Character &copy) : name(copy.name) {
	for (int i = 0; i < 4; i++) {
		if (copy->inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &assign) {
	if (this != &assign) {
		this->name = assign.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			if (this->inventory[i])
				this->inventory[i] = assign.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->inventory[idx]) {
		delete this->inventory[idx];
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && this->inventory[idx])
			this->inventory[idx]->use(target);

}
