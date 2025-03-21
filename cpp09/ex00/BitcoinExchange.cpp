#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <climits>

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
    {
        if (this->_bitcoinPrices.size())
        {
            this->_bitcoinPrices.clear();
            this->_bitcoinPrices = other._bitcoinPrices;
        }
    }
    return *this;
}

void BitcoinExchange::parse_csv() {
    std::ifstream file("data.csv");

    if (!file) {
        throw std::runtime_error("File cannot open");
    }

    std::string line, date, price_str;
    std::getline(file, line);
    while(std::getline(file, line)) {
        char *endptr;
        std::stringstream ss(line);
        std::getline(ss, date, ',');
        std::getline(ss, price_str);
        float price = std::strtof(price_str.c_str(), &endptr);

        if (endptr == price_str.c_str() || price < 0.0)
            throw std::runtime_error("incorrect price: " + price_str);
        while (*endptr) {
            if (!std::isspace(*endptr)) {
                throw std::runtime_error("invalid characters: " + price_str);
            }
            ++endptr;
        }
        if (_bitcoinPrices.find(date) != _bitcoinPrices.end()) {
            throw std::runtime_error("duplicate date: " + date);
        }
        if (!checkDate(date))
            throw std::runtime_error("incorrect date: " + date);
        _bitcoinPrices[date] = price;
    }

    file.close();
}

bool BitcoinExchange::checkDate(std::string date_str) {
    char date[date_str.size() + 1];
    std::strcpy(date, date_str.c_str());
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));

    if (!strptime(date, "%Y-%m-%d", &tm))
        return false;

    // Reconstruct the date based on tm
    std::stringstream ss;
    ss << (tm.tm_year + 1900) << '-'
       << std::setw(2) << std::setfill('0') << (tm.tm_mon + 1) << '-'
       << std::setw(2) << std::setfill('0') << tm.tm_mday;
    // Compare if the date had changed
    return ss.str() == date_str;
}

void BitcoinExchange::calcul(char *f) {
    std::ifstream file(f);
    std::string line, date, nb_str;

    if (!file) {
        throw std::runtime_error("File cannot open");
    }

    std::getline(file, line);
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, date, '|');
        std::getline(ss, nb_str);

        // remove spaces
        date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
        nb_str.erase(std::remove(nb_str.begin(), nb_str.end(), ' '), nb_str.end());

        float nb = std::strtof(nb_str.c_str(), NULL);
        // Check if nb_str contains only digits
        bool is_digit = true;
        for (size_t i = 0; i < nb_str.size(); ++i) {
            if (!std::isdigit(nb_str[i])) {
                is_digit = false;
                break;
            }
        }
        if (!is_digit) {
            std::cout << "Error: not a valid number => " << nb_str << std::endl;
            continue;
        }
        if (!checkDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (nb < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (nb > INT_MAX) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = _bitcoinPrices.lower_bound(date);
        if (it != _bitcoinPrices.end()) {
            std::cout << it->first << " => " << nb << " = " << it->second * nb << std::endl;
        } else {
            std::cout << "Date not found: " << date << std::endl;
        }
    }

    file.close();
}