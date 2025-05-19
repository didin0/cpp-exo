#include "PresidentialPardonForm.hpp"

PPForm::PPForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {
}

PPForm::~PPForm() {
}

PPForm::PPForm(const PPForm &copy) : Form(copy), target(copy.target) {
}

PPForm& PPForm::operator=(const PPForm& assign) {
	if (this != &assign) {
		Form::operator=(assign);
		this->target = assign.target;
	}
	return *this;
}

void PPForm::execute(Bureaucrat const &executor) const {
	if (!this->getSign())
		throw Form::FormNotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

