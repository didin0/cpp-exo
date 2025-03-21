#include "iter.hpp"

void printElement(double& element) {
    std::cout << element << " ";
}

int main( void ) {
    double a[5] = {1, 2, 3, 4, 5};
    ::iter( a, 5, printElement);


    return 0;
}