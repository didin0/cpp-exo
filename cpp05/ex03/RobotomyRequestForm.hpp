#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RRForm : public Form {
	public:
		RRForm(std::string target);
		~RRForm();
		RRForm(const RRForm &copy);
		RRForm& operator=(const RRForm &assign);

		void execute(Bureaucrat const &executor) const;
	private:
		std::string target;
};

#endif
