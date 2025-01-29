#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>

bool ScalarConverter::isChar(const std::string &literal) {
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal) {
    std::istringstream iss(literal);
    long long value;
    iss >> value;
    return !iss.fail() && iss.eof() &&
           value <= std::numeric_limits<int>::max() &&
           value >= std::numeric_limits<int>::min();
}

bool ScalarConverter::isFloat(const std::string &literal) {
    if (literal.empty() || literal[literal.length() - 1] != 'f') // Doit se terminer par 'f'
        return false;

    std::string withoutF = literal.substr(0, literal.length() - 1); // Supprime 'f'
    std::stringstream ss(withoutF);
    float value;
    ss >> value;
    return !ss.fail() && ss.eof();
}



bool ScalarConverter::isDouble(const std::string &literal) {
    std::stringstream ss(literal);
    double value;
    ss >> value;
    return !ss.fail() && ss.eof();
}

// Convert the literal to various types and display the conversions.
void ScalarConverter::convert(const std::string& literal) {
    // Cas spéciaux
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" ||
        literal == "+inff" || literal == "-inff") {
        handleSpecialCases(literal);
        return;
    }

    // Détection et conversion
    if (isChar(literal)) {
        char c = literal[0];
        displayConversions(static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), c);
    } else if (isInt(literal)) {
        std::istringstream iss(literal);
        long long intValue;
        iss >> intValue;
        if (intValue > std::numeric_limits<int>::max() || intValue < std::numeric_limits<int>::min()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: non displayable" << std::endl;
            std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(intValue) << std::endl;
        } else {
            displayConversions(static_cast<int>(intValue), static_cast<float>(intValue), static_cast<double>(intValue));
        }
    } else if (isFloat(literal)) {
        std::string withoutF = literal.substr(0, literal.length() - 1); // Supprime le 'f'
        double f;
        std::istringstream(withoutF) >> f;
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: non displayable" << std::endl;
			std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
            std::cout << "double: " << f << std::endl;
        } else {
            displayConversions(static_cast<int>(f), f, static_cast<double>(f));
        }
    } else if (isDouble(literal)) {
        double d;
        std::istringstream(literal) >> d;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: non displayable" << std::endl;
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } else {
            displayConversions(static_cast<int>(d), static_cast<float>(d), d);
        }
    } else {
        std::cerr << "Error: Invalid literal" << std::endl;
    }
}


// Handle special cases such as "nan" and "inf"
void ScalarConverter::handleSpecialCases(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// Display conversion results for char, int, float, and double
void ScalarConverter::displayConversions(int i, float f, double d, char c) {
    // Display char
    if (i < 0 || i > 127 || !std::isprint(c)) {
        std::cout << "char: impossible" << std::endl;
    } else {
        std::cout << "char: '" << c << "'" << std::endl;
    }

    // Display int
    std::cout << "int: " << i << std::endl;

    // Display float and double with proper formatting
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;

    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

// Overloaded displayConversions without char
void ScalarConverter::displayConversions(int i, float f, double d) {
    displayConversions(i, f, d, static_cast<char>(i));
}

