#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& assign);
	private:
		std::string type;
		void makeSound() const;
};

#endif

