#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {
}

AMateria::~AMateria() {
}

AMateria::AMateria(const AMateria &copy) : type(copy.type) {
}

AMateria &AMateria::operator=(const AMateria &assign) {
	if (this != &assign) 
		this->type = assign.type;
	return *this;
}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Materia " << target.getName() << " is used" << std::endl;
}
