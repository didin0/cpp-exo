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

void    Contact::display_list(Contact Contact, int list_num)
{
	std::cout << "|" << std::right << std::setfill(' ') << std::setw(10) << list_num << "|";
	truncate(Contact.FirstName);
	truncate(Contact.LastName);
	truncate(Contact.NickName);
	std::cout << std::endl;
	std::cout << "|" << std::setfill('-') << std::setw(44) << "|" << std::endl;
}

void    Contact::truncate(const std::string str)
{
	if (str.length() <= 10)
		std::cout << std::right << std::setfill(' ') << std::setw(10) << str << "|";
	else
	{
		for(size_t i = 0; i < 9; i++)
			std::cout << std::left << std::setw(1) << str[i];
		std::cout << "." << "|";
	}
}
