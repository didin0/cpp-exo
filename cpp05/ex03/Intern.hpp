#include "AForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        Form* makeForm(const std::string& formName, const std::string& target);
    private:
        Form* createRobotomyForm(const std::string& target);
        Form* createPresidentialForm(const std::string& target);
        Form* createShrubberyForm(const std::string& target);
};
