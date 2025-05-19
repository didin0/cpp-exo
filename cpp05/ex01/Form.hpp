#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool sign;
		const int grade;
		const int gradeExec;
	public:
		Form(const std::string name, const int grade, const int gradeExec);
		~Form();
		Form(const Form &copy);
		Form& operator=(const Form &assign);	

		std::string getName() const;
		bool getSign() const;
		int getGrade() const;
		int getGradeExec() const;
		
		void beSigned(Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

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
};

std::ostream& operator<<(std::ostream& os, const Form &Form);
#endif
