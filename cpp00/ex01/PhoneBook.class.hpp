#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook {
	private:
		Contact Contacts[8];
	public:
		void starto_program(void);
		void search_user(Contact Contacts[8], size_t i);
		void display_all(Contact Contacts[8], size_t i);
		PhoneBook(void);
		~PhoneBook(void);	
};

#endif
