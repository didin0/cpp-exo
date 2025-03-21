#pragma once
#include <vector>

class Span {
    public:
        void addNumber(int n);
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