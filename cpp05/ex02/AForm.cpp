#include "AForm.hpp"

Form::Form(const std::string name, const int grade) : name(name), sign(false), grade(grade), gradeExec(1) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string name, const int grade, const int gradeExec) : name(name), sign(false), grade(grade), gradeExec(gradeExec)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	if (gradeExec < 1)
		throw GradeTooHighException();
	else if (gradeExec > 150)
		throw GradeTooLowException();
}

Form::~Form() {
}

Form::Form(const Form &copy) : name(copy.name), sign(copy.sign), grade(copy.grade), gradeExec(copy.gradeExec) {
}

Form& Form::operator=(const Form &assign) {
	if (this != &assign) {
		sign = assign.sign;
	}
	return *this;
}

std::string Form::getName() const {
	return name;
}

bool Form::getSign() const {
	return sign;
}

int Form::getGrade() const {
	return grade;
}

int Form::getExecGrade() const {
	return gradeExec;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->grade) {
		throw Form::GradeTooLowException();
	}
	this->sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form &form) {
	os << form.getName() << ", form grade " << form.getGrade() << ". Signed: " << (form.getSign() ? "Yes" : "No");
	return os;
}
