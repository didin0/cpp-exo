#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

Class ClapTrap {
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator(const ClapTrap& assign);
		void attack(const std::string& target);
		void takeDamage(unsigned int amout);
		void beRepaired(unsigned int amout);
		std::string getName();
	private:
		std::string name;
		unsigned int HP;
		unsigned int EP;
		unsigned int AD;
};

#endif
