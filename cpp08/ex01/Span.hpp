#pragma once
#include <vector>
#include <iterator>

class Span {
    public:
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end); // New function
        int shortestSpan();
        int longestSpan();
        Span(unsigned int size);
        ~Span();
        Span();
        Span& operator=(const Span & other);
        Span(const Span & other);
    private:
        unsigned int _size;
        std::vector<int> _container;
};