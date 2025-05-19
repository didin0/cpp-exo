#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &assign);

		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(Form &form);	
		void executeForm(Form &form) const; 

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat &Bureaucrat);

#endif
