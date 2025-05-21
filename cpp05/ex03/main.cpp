#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern someRandomIntern;
    Form* form;

    // Test 1: ShrubberyCreationForm
    form = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (form) {
        std::cout << *form << std::endl;
        delete form; // Libérer la mémoire
    }

    // Test 2: RobotomyRequestForm
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form; // Libérer la mémoire
    }

    // Test 3: PresidentialPardonForm
    form = someRandomIntern.makeForm("presidential pardon", "criminal");
    if (form) {
        std::cout << *form << std::endl;
        delete form; // Libérer la mémoire
    }

    // Test 4: Formulaire invalide
    form = someRandomIntern.makeForm("invalid form", "target");
    if (!form) {
        std::cout << "Invalid form creation handled correctly." << std::endl;
    }

    return 0;
}