#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->materia[i])
			delete this->materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	for (int i = 0; i < 4; i++) {
		if (copy.materia[i])
			this->materia[i] = copy.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &assign) {
	if (this != &assign) {
		for (int i = 0; i < 4; i++) {
			if (this->materia[i])
				delete this->materia[i];
			if (assign.materia[i])
				this->materia[i] = assign.materia[i]->clone();
			else
				this->materia[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *learn) {
	for (int i = 0; i < 4; i++) {
		if (!this->materia[i]) {
			this->materia[i] = learn;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->materia[i] && this->materia[i]->getType() == type)
			return this->materia[i]->clone();
	}
	return NULL;
}

