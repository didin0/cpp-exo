#include "iter.hpp"
#include <iostream>
#include <string>

// Fonction pour afficher un élément (non-const)
template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

// Fonction pour afficher un élément (const)
template <typename T>
void printElementConst(const T& element) {
    std::cout << element << " ";
}

// Fonction pour incrémenter un élément (non-const)
template <typename T>
void incrementElement(T& element) {
    element++;
}

int main() {
    // Test avec un tableau d'entiers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    ::iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    ::iter(intArray, intArraySize, incrementElement);

    std::cout << "Incremented int array: ";
    ::iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    // Test avec un tableau de chaînes de caractères
    std::string strArray[] = {"Hello", "World", "C++", "Templates"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    ::iter(strArray, strArraySize, printElement);
    std::cout << std::endl;

    // Test avec un tableau de doubles (const)
    const double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Const double array: ";
    ::iter(doubleArray, doubleArraySize, printElementConst);
    std::cout << std::endl;

    return 0;
}