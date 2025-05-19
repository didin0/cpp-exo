#include "ShrubberyCreationForm.hpp"
#include <fstream>

SCForm::SCForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {
}

SCForm::~SCForm() {
}

SCForm::SCForm(const SCForm &copy) : Form(copy), target(copy.target) {
}

SCForm& SCForm::operator=(const SCForm& assign) {
	if (this != &assign) {
		Form::operator=(assign);
		this->target = assign.target;
	}
	return *this;
}

void SCForm::execute(Bureaucrat const &executor) const {
	if (!this->getSign())
		throw Form::FormNotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();

	std::ofstream ofs((this->target + "_shrubbery").c_str());
	if (!ofs) {
		std::cerr << "Error creating file" << std::endl;
		return;
	}

	ofs << "       ###" << std::endl;
    ofs << "      #o###" << std::endl;
    ofs << "    #####o###" << std::endl;
    ofs << "   #o#\\#|#/###" << std::endl;
    ofs << "    ###\\|/#o#" << std::endl;
    ofs << "     # }|{  #" << std::endl;
    ofs << "       }|{" << std::endl;

	ofs.close();
}
