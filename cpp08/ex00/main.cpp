#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    // Test with a vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found at index: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Test with a list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found at index: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Test with a missing value
    try {
        easyfind(vec, 99);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
