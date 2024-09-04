#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap {
	public : 
		ScravTrap(std::string name);	
		~ScravTrap();
		ScravTrap(const ScravTrap& copy);
		ScravTrap& operator=(const ScravTrap& assign);
		void attack(const std::string& target);
		void guardGate();
};

#endif
