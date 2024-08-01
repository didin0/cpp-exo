#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() {
    std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook destructor called" << std::endl;
    // Clean up resources if necessary
}

void	PhoneBook::starto_program() {
	std::string option;
	size_t i = 0;

	while(1) {
		std::cout << "Please enter an option: ADD, SEARCH or EXIT" << std::endl;
		getline(std::cin, option);
		if (option == "ADD")
		{
			Contacts[i].add_user();
			display_all(Contacts, i);
			i++;
		}
	//	else if (option == "SEARCH")
			// do smt
		else if (option == "EXIT" || std::cin.eof())
			break;
		else
			std::cout << "Invalid input: " << option  << std::endl;
		if (i == 8)
			i = 0;
	}
}
void	PhoneBook::display_all(Contact Contacts[8], size_t i) {
	size_t j = 0;
	while (j >= i)
	{
		std::cout << "Contact: " << i << std::endl;

		Contacts[i].display();
		j++;
	}
}

