#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PPForm : public Form {
	public:
		PPForm(std::string target);
		~PPForm();
		PPForm(const PPForm &copy);
		PPForm& operator=(const PPForm &assign);

		void execute(Bureaucrat const &executor) const;
	private:
		std::string target;
};

#endif
