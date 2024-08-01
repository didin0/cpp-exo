#include <iostream>
#include "Contact.class.hpp"

Contact::Contact() {
    std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact() {
    std::cout << "Contact destructor called" << std::endl;
}

void Contact::add_user() {
    std::cout << "Enter First Name: ";
    std::getline(std::cin, this->FirstName);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, this->LastName);

    std::cout << "Enter Nick Name: ";
    std::getline(std::cin, this->NickName);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, this->PhoneNumber);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, this->DarkestSecret);
}

void Contact::display() const {
    std::cout << "First Name: " << this->FirstName << std::endl;
    std::cout << "Last Name: " << this->LastName << std::endl;
    std::cout << "Nick Name: " << this->NickName << std::endl;
    std::cout << "Phone Number: " << this->PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->DarkestSecret << std::endl;
}

