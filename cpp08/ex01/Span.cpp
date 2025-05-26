#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <iostream>

Span::Span()
{
    _size = 0;
}

Span::Span(unsigned int size) : _size(size)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_size = other._size;
        if (this->_container.size())
        {
            this->_container.clear();
            this->_container = other._container;
        }
    }
    return *this;
}

Span::Span(const Span &other) : _size(other._size)
{
    *this = other;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_container.size() <= _size)
        _container.push_back(n);
    else
        throw std::runtime_error("size already max");
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t rangeSize = std::distance(begin, end);

    if (_container.size() + rangeSize > _size) {
        throw std::runtime_error("Adding these numbers would exceed the maximum size of the Span");
    }

    _container.insert(_container.end(), begin, end);
}

int Span::shortestSpan()
{
    std::sort(_container.begin(), _container.end());

    int minSpan = INT_MAX;

    if (_container.size() > 2) {
        for (size_t i = 1; i < _container.size(); ++i)
        {
            int span = _container[i] - _container[i - 1];
            if (span < minSpan)
                minSpan = span;
        }
        return minSpan;
    }
    else
        throw std::runtime_error("0 or 1 element");
}

int Span::longestSpan()
{
    int min = *min_element(_container.begin(), _container.end());
    int max = *max_element(_container.begin(), _container.end());
    if (_container.size() > 2)
        return (max - min);
    else
        throw std::runtime_error("0 or 1 element");
}