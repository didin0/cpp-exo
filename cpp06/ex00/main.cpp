#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    // Convert the input argument using ScalarConverter
    std::string input = argv[1];
    ScalarConverter::convert(input);

    return 0;
}

