#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& assign);
		void setBrain(Brain *brain);
		std::string getIdea(int i) const;
	private:
		std::string type;
		void makeSound() const;
		Brain *brain;
};

#endif
