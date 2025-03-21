#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <exception>
#include "Array.hpp"

int main() {
    try {
        // Test 1: Default Constructor (Empty Array)
        std::cout << "Test 1: Default Constructor\n";
        Array<int> emptyArray;
        std::cout << "Size: " << emptyArray.size() << " (Expected: 0)\n\n";

        // Test 2: Constructor with Size
        std::cout << "Test 2: Constructor with Size\n";
        Array<int> intArray(5);
        std::cout << "Size: " << intArray.size() << " (Expected: 5)\n";

        // Initialize and print values
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 2;  // 0 2 4 6 8
        }

        std::cout << "Values: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << "\n\n";

        // Test 3: Copy Constructor
        std::cout << "Test 3: Copy Constructor\n";
        Array<int> copyArray = intArray;  // Deep copy
        std::cout << "Copied Values: ";
        for (unsigned int i = 0; i < copyArray.size(); i++) {
            std::cout << copyArray[i] << " ";
        }
        std::cout << "\n\n";

        // Modify the original array to verify deep copy
        intArray[0] = 100;
        std::cout << "After modifying intArray[0]:\n";
        std::cout << "Original: " << intArray[0] << " (Expected: 100)\n";
        std::cout << "Copy: " << copyArray[0] << " (Expected: 0, should be unchanged)\n\n";

        // Test 4: Assignment Operator
        std::cout << "Test 4: Assignment Operator\n";
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned Values: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << "\n\n";

        // Test 5: Out-of-Bounds Access
        std::cout << "Test 5: Out-of-Bounds Access (Expect Exception)\n";
        std::cout << intArray[10];  // Should throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << "\n\n";
    }

    // Test 6: Working with Different Types
    std::cout << "Test 6: Working with Different Types (Strings)\n";
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "42";
    strArray[2] = "World";

    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << "\n\n";

    return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }