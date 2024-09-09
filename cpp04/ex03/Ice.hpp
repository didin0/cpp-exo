#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : AMateria("ice") {
	public:
		Ice();
		~Ice();
		Ice(const &copy);
		Ice& operator=(const &assign);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
