#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &literal) {
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal) {
    std::stringstream ss(literal);
    int value;
    ss >> value;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isFloat(const std::string &literal) {
    if (literal.find('f') == std::string::npos)
        return false;
    std::stringstream ss(literal);
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

void ScalarConverter::convert(const std::string &literal) {
    if (isChar(literal)) {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
    else if (isInt(literal)) {
        int i;
        std::stringstream(literal) >> i;
        printChar(static_cast<char>(i));
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    }
    else if (isFloat(literal)) {
        float f;
        std::stringstream(literal) >> f;
        printChar(static_cast<char>(f));
        printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
    }
    else if (isDouble(literal)) {
        double d;
        std::stringstream(literal) >> d;
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    } else {
        std::cout << "Invalid literal: " << literal << std::endl;
    }
}

void ScalarConverter::printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    if (std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    if (std::isnan(d) || std::isinf(d))
        std::cout << "double: " << d << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

