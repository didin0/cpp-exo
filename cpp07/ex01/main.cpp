#include <iostream>

template <typename T> void iter(T* array, size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; i++) {  
        func(array[i]);
    }
}

void printElement(double& element) {
    std::cout << element << " ";
}

int main( void ) {
    double a[5] = {1, 2, 3, 4, 5};
    ::iter( a, 5, printElement);


    return 0;
}