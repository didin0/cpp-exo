#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria* inventory[4];
	public:
		Character(std::string const &name);
		virtual ~Character();
		Character(const Character &copy);
		Character& operator=(const Character &assign);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
