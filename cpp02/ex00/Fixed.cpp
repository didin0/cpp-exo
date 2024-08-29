#include "Fixed.hpp"

Fixed::Fixed() : fixe(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->fixe = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& assign) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign) {
		this->fixe = assign.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixe;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixe = raw;
}
