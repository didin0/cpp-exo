#include "PhoneBook.class.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) { // Vérification pour EOF ou erreur
            std::cout << std::endl << "SIG DETECTED. Exiting the program." << std::endl;
            break;
        }

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT.\n";
        }
    }

    return 0;
}

