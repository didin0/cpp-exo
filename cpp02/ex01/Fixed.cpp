#include "Fixed.hpp"

Fixed::Fixed() : fixe(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number) : fixe(number << rawBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const number) : fixe(roundf(number * (1 << rawBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Version plus opti Performance / Clarté
Fixed::Fixed(const Fixed& copy) : fixe(copy.getRawBits()) {
    std::cout << "Copy constructor called" << std::endl;
}

// Version qui print plus de message mais moins opti
//Fixed::Fixed(const Fixed &copy) {
//    std::cout << "Copy constructor called" << std::endl;
//    *this = copy;
//}


Fixed &Fixed::operator=(const Fixed& assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        this->fixe = assign.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const {
    return this->fixe;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixe = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->fixe) / (1 << rawBits);
}

int Fixed::toInt() const {
    return this->fixe >> rawBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

