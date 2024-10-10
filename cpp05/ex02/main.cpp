#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
std::cout << "----\n"; // ShrubberyCreationForm	
	try {
        Bureaucrat bob("Bob", 100);
        SCForm shrubbery("home");

        std::cout << shrubbery << std::endl;

        // Bob signs the form
        bob.signForm(shrubbery);

        // Bob tries to execute the form
        bob.executeForm(shrubbery);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
std::cout << "----\n"; // RobotomyRequestForm
    try {
        Bureaucrat bob("Bob", 72);
        RRForm robotomy("Bob");

        std::cout << robotomy << std::endl;

        // Bob signs the form
        bob.signForm(robotomy);

        // Bob tries to execute the form
        bob.executeForm(robotomy);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
std::cout << "----\n"; // PresidentialPardonForm
    try {
        Bureaucrat bob("Bob", 5);
        PPForm pardon("Bob");

        std::cout << pardon << std::endl;

        // Bob signs the form
        bob.signForm(pardon);

        // Bob tries to execute the form
        bob.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}

