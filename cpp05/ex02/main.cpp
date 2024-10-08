#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main() {
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

    return 0;
}

