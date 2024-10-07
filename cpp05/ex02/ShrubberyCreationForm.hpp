#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class SCForm : public Form() {
	public:
		SCForm(std::string target);
		~SCForm();
		SCForm(const SCForm &copy);
		SCForm& operator=(const SCForm &assign); 
		
		void execute(Bureaucrat const &executor) const;
}

#endif
