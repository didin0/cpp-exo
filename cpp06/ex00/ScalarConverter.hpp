#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cmath>

class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    // Canonical form
    ScalarConverter() {}
    ~ScalarConverter() {}
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter& operator=(const ScalarConverter &assign);

    // Helper functions for detecting types
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

    // Conversion functions
    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);

    static void handleSpecialCases(const std::string& literal);
    static void displayConversions(int i, float f, double d, char c);
    static void displayConversions(int i, float f, double d);
};

#endif

