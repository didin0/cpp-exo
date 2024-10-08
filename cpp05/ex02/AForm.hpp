#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool sign;
		const int grade;
		const int gradeExec;
	public:
		Form(const std::string name, const int grade);
		Form(const std::string name, const int grade, int gradeExec);
		~Form();
		Form(const Form &copy);
		Form& operator=(const Form &assign);	

		std::string getName() const;
		bool getSign() const;
		int getGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high!";
			}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
            		return "Grade is too low!";
        	}
		};
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form isn´t been signed!";
			}
		};
};

std::ostream& operator<<(std::ostream& os, const Form &Form);
#endif
