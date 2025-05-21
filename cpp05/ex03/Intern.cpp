#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
    }
    return *this;
}

Form* Intern::createRobotomyForm(const std::string& target) {
    return new RRForm(target);
}
Form* Intern::createPresidentialForm(const std::string& target) {
    return new PPForm(target);
}
Form* Intern::createShrubberyForm(const std::string& target) {
    return new SCForm(target);
}

Form* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Tableau associant les noms des formulaires à leurs fonctions de création
    const std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    Form* (Intern::*formCreators[])(const std::string&) = {
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm,
        &Intern::createShrubberyForm
    };

    // Parcourir le tableau pour trouver le formulaire correspondant
    for (size_t i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            Form* form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    // Si aucun formulaire ne correspond
    std::cerr << "Intern can't create this form: \"" << formName << "\"" << std::endl;
    return NULL;
}