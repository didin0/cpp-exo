#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &copy) : AMateria(copy) {}

Ice &Ice::operator=(const Ice &assign) {
    if (this != &assign) {
        AMateria::operator=(assign);
    }
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
