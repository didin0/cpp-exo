#include "RobotomyRequestForm.hpp"

RRForm::RRForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {
}

RRForm::~RRForm() {
}

RRForm::RRForm(const RRForm &copy) : Form(copy), target(copy.target) {
}

RRForm& RRForm::operator=(const RRForm& assign) {
	if (this != &assign) {
		Form::operator=(assign);
		this->target = assign.target;
	}
	return *this;
}

void RRForm::execute(Bureaucrat const &executor) const {
	if (!this->getSign())
		throw Form::FormNotSignedException();
	
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();

	std::cout << "****robot noises****" << std::endl;
	srand(time(NULL));
	int random = rand() % 2;
	if (random == 0)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}
