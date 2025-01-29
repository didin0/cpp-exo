#include "Serializer.hpp"

int main() {
    // Création d'une instance de Data
    Data originalData;
    originalData.n = 42;

    std::cout << "Original Data Address: " << &originalData << std::endl;
    std::cout << "Original Data Value: " << originalData.n << std::endl;

    // Sérialisation
    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized Data (raw uintptr_t): " << raw << std::endl;

    // Désérialisation
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data Value: " << deserializedData->n << std::endl;

    // Vérification
    if (deserializedData == &originalData) {
        std::cout << "Deserialization successful! The addresses match." << std::endl;
    } else {
        std::cout << "Deserialization failed! The addresses do not match." << std::endl;
    }

    return 0;
}

