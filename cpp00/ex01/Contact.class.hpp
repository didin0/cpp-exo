#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    Contact();
    ~Contact();
    void add_user();
    void display() const; // Method to display the contact information
	void display_list(Contact Contact, int i);
	void truncate(const std::string str);
};

#endif

