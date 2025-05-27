#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        // Test 1 : Span avec une taille de 1
        std::cout << "Test 1: Span avec une taille de 1" << std::endl;
        Span sp1(1);
        sp1.addNumber(42);

        try {
            std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test 2 : Span vide
        std::cout << "\nTest 2: Span vide" << std::endl;
        Span sp2(0);

        try {
            sp2.shortestSpan();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            sp2.longestSpan();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test 3 : Ajouter plus de nombres que la capacité
        std::cout << "\nTest 3: Dépassement de capacité" << std::endl;
        Span sp3(2);
        sp3.addNumber(1);
        sp3.addNumber(2);
        sp3.addNumber(3);

        try {
            sp3.addNumber(3); // Dépassement de capacité
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test 4 : Calcul des spans avec une taille normale
        std::cout << "\nTest 4: Calcul des spans avec une taille normale" << std::endl;
        Span sp4(5);
        sp4.addNumber(5);
        sp4.addNumber(3);
        sp4.addNumber(17);
        sp4.addNumber(9);
        sp4.addNumber(11);

        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp4.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}