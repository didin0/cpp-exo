#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Form formA("FormA", 30, 40);

        std::cout << formA << std::endl;

        // Tentative de signer et d'exécuter
        formA.beSigned(john);
        std::cout << formA << std::endl;

        john.signForm(formA);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat jane("Jane", 100);
        Form formB("FormB", 50, 90);

        std::cout << formB << std::endl;

        // Tentative d'exécution sans signature
        jane.signForm(formB);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 150);
        Form formC("FormC", 50, 140);

        std::cout << formC << std::endl;

        // Tentative de signer et d'exécuter avec un grade insuffisant
        formC.beSigned(bob);
        bob.signForm(formC);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}