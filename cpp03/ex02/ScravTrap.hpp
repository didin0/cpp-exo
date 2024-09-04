#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap {
	public : 
		ScravTrap(std::string name);	
		~ScravTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif
