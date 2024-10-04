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

void Brain::setIdea(std::string idea) {
    int i = 0;
    while (i < 100) {
        if (ideas[i].empty()) { // Si l'idée est vide, on la remplit
            ideas[i] = idea;
            break;
        }
        i++;
    }
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100) {
        return ideas[i];
    }
    return "";
}
