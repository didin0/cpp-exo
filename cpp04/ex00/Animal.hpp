#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	public:
		Animal(std::string type);
		Animal();
		~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& assign);
		virtual void makeSound() const;
	protected:
		std::string type;
}

#endif
