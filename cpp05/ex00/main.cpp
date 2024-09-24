#include "Bureaucrat.hpp"

int main() {
    try {
        // Test 1: Valid Bureaucrat creation
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        // Test 2: Increment Bureaucrat's grade (valid)
        john.increment();
        std::cout << "After incrementing, " << john << std::endl;

        // Test 3: Decrement Bureaucrat's grade (valid)
        john.decrement();
        std::cout << "After decrementing, " << john << std::endl;

        // Test 4: Invalid grade (too high)
        try {
            Bureaucrat highRank("Alice", 0);
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test 5: Invalid grade (too low)
        try {
            Bureaucrat lowRank("Bob", 151);
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test 6: Increment Bureaucrat grade to trigger GradeTooHighException
        try {
            Bureaucrat topRank("Eve", 1);
            topRank.increment();
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test 7: Decrement Bureaucrat grade to trigger GradeTooLowException
        try {
            Bureaucrat bottomRank("Charlie", 150);
            bottomRank.decrement();
        } catch (const std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "An unexpected exception occurred: " << e.what() << std::endl;
    }

    return 0;
}

