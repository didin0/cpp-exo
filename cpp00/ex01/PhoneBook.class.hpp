#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int oldestIndex;
    int contactCount;

    std::string truncate(const std::string &str) const;

public:
    PhoneBook();

    void addContact();
    void searchContact() const;
};

#endif

