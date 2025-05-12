#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pmerge(argv);
        pmerge.sortAndCompare();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}