#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
	public : 
		FlagTrap(std::string name);	
		~FlagTrap();
		void highFivesGuys();
};

#endif

