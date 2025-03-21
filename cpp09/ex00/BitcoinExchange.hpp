#pragma once
#include <map>
#include <iostream>

class BitcoinExchange {
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        void parse_csv();
        void calcul(char *file);
    private:
        std::map<std::string, float> _bitcoinPrices;
        bool checkDate(std::string date);
};