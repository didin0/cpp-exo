#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
	// Création de la source de materia
	MateriaSource src;
	src.learnMateria(new Ice());  // Apprend l'élément "ice"
	src.learnMateria(new Cure()); // Apprend l'élément "cure"

	// Création d'un personnage
	Character* me = new Character("me");

	// Création d'une Materia à partir de la source et ajout dans l'inventaire du personnage
	AMateria* tmp;
	tmp = src.createMateria("ice");
	me->equip(tmp); // Equip "ice" materia

	tmp = src.createMateria("cure");
	me->equip(tmp); // Equip "cure" materia

	// Création d'un autre personnage
	Character* bob = new Character("bob");
	// Il n'est pas possible de check si une reference est NULL ????

	// Utilisation des Materias du personnage sur un autre personnage
std::cout << "-------------------------" << std::endl;
	me->use(0, *bob); // Utilise "ice" sur Bob
	me->use(1, *bob); // Utilise "cure" sur Bob
std::cout << "-------------------------" << std::endl;

	// Vérification de l'utilisation des Materias après une déséquipée
	me->unequip(1); // Déséquipe la Materia cure
	me->use(1, *bob); // Tente d'utiliser la Materia déséquipée (ne devrait rien faire)

	// Nettoyage mémoire
	delete bob;
	delete me;
	return 0;
}

