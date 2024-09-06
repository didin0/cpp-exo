#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	std::cout << "Constructor for Brain" << std::endl;
}

Brain::~Brain() { 
	std::cout << "Destructor for Brain" << std::endl;
}

Brain::Brain(const Brain& copy) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "Constructor by copy for Brain" << std::endl;
}

Brain& Brain::operator=(const Brain& assign) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = assign.ideas[i];
	return *this;
}
