#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& assign);
	private:
		std::string type;
		void makeSound() const;
};

#endif

