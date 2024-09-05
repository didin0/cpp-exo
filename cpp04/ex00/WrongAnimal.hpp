#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	public:
		WrongAnimal(std::string type);
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& assign);
		void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif
