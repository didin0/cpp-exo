#include <iostream>
#include "Span.hpp"
#include <exception>

int main()
{
    Span sp = Span(5);
    try {

    sp.addNumber(58);
    sp.addNumber(2);
    sp.addNumber(4);
    sp.addNumber(8);
    sp.addNumber(16);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
       std::cout << e.what() << std::endl;
    }
    return 0;
}