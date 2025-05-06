#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include <utility>
#include <cstddef>

class PmergeMe
{
public:
    PmergeMe(char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void sort();

private:
    std::vector<int> _numbers;
    void printNumbers() const;
    void fordJohnsonSort(std::vector<int> &tab);
    void sortPairs(const std::vector<int> &tab, std::vector<std::pair<int, int> > &pairs, bool &hasOdd, int &oddElement);
    std::vector<size_t> generateJacobsthalIndices(size_t n);
    void insertPetits(const std::vector<int> &petits, std::vector<int> &sorted);
};

#endif
