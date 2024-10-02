#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Création de bureaucrates avec des grades valides
        Bureaucrat bob("Bob", 75);
        Bureaucrat alice("Alice", 1);
        Bureaucrat charlie("Charlie", 150);

        // Affichage des informations des bureaucrates
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << charlie << std::endl;

        // Incrémentation de Bob
        std::cout << "\nIncrementing Bob's grade..." << std::endl;
        bob.increment();
        std::cout << bob << std::endl;

        // Tentative de décrémentation de Charlie
        std::cout << "\nDecrementing Charlie's grade..." << std::endl;
        try {
            charlie.decrement();  // Cela déclenche une exception
            std::cout << charlie << std::endl;
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Création de formulaires
        Form formA("FormA", 50);
        Form formB("FormB", 100);

        // Bob essaie de signer formA et formB
        std::cout << "\n-- Tentative de signature par Bob --" << std::endl;
        bob.signForm(formA);
        bob.signForm(formB);
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        // Alice (grade 1) essaie de signer formA
        std::cout << "\nAlice trying to sign FormA..." << std::endl;
        alice.signForm(formA);

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Tentative de création d'un bureaucrate avec un grade invalide
        std::cout << "\nTrying to create a bureaucrat with invalid grade 0..." << std::endl;
        Bureaucrat invalidBureaucrat("Invalid", 0);  // Devrait déclencher une exception
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Tentative de création d'un formulaire avec un grade invalide
        std::cout << "\nTrying to create a form with invalid grade 200..." << std::endl;
        Form invalidForm("InvalidForm", 200);  // Devrait déclencher une exception
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

