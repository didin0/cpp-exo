#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& assign);
	private:
		std::string type;
		void makeSound() const;
};

#endif
