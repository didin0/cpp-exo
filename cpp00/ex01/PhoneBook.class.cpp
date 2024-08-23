#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() : oldestIndex(0), contactCount(0) {}

std::string PhoneBook::truncate(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setDarkestSecret(input);

    if (contactCount < 8) {
        contacts[contactCount++] = newContact;
    } else {
        contacts[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }

    std::cout << "Contact added successfully.\n";
}

void PhoneBook::searchContact() const {
    if (contactCount == 0) {
        std::cout << "PhoneBook is empty.\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter index of the contact to view: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= contactCount) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Invalid index.\n";
    } else {
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    }
}

