#include "Fixed.hpp"

Fixed::Fixed() : fixe(0) {
}

Fixed::Fixed(int const number) : fixe(number << rawBits) {
}

Fixed::Fixed(float const number) : fixe(roundf(number * (1 << rawBits))) {
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed& copy) : fixe(copy.getRawBits()) {
}

Fixed &Fixed::operator=(const Fixed& assign) {
    if (this != &assign) {
        this->fixe = assign.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const {
    return this->fixe;
}

void Fixed::setRawBits(int const raw) {
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

bool Fixed::operator>(const Fixed& other) const {
    return this->fixe > other.fixe;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->fixe < other.fixe;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->fixe >= other.fixe;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->fixe <= other.fixe;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->fixe == other.fixe;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->fixe != other.fixe;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    this->fixe++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->fixe--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

