#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& assign);
		void setBrain(Brain *brain);
		std::string getIdea(int i) const;
	private:
		std::string type;
		void makeSound() const;
		Brain *brain;
};

#endif
