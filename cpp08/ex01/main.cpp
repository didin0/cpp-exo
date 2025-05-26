#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    Span sp(10);

    sp.addNumber(5);
    sp.addNumber(10);

    int arr[] = {20, 30, 40, 50};
    std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

    sp.addNumbers(numbers.begin(), numbers.end());

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    return 0;
}