#pragma once
#include <iostream>

template <typename T> void iter(T* array, size_t length, void (*func)(T&)) {
    if (!array || length == 0 || !func) {
        std::cerr << "Error: Invalid input to iter function." << std::endl;
        return;
    }
    for (size_t i = 0; i < length; i++) {  
        func(array[i]);
    }
}