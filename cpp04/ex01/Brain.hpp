#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain {
	public:
		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& assign);
		std::string ideas[100];
		void setIdea(std::string idea);
		std::string getIdea(int i) const;
};

#endif
