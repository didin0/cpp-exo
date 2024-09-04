#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
	public : 
		FlagTrap(std::string name);	
		~FlagTrap();
		FlagTrap(const FlagTrap& copy);
		FlagTrap& operator=(const FlagTrap& assign);

		void highFivesGuys();
};

#endif

