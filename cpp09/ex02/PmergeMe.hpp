#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <utility>
#include <cstddef>
#include <ctime>

class PmergeMe
{
public:
    PmergeMe(char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void sortAndCompare();

private:
    std::vector<int> _numbers;

    void printSequence(const std::vector<int> &container) const;

    template <typename Container>
    void fordJohnsonSort(Container &tab);

    template <typename Container>
    void sortPairs(const Container &tab, std::vector<std::pair<int, int> > &pairs, bool &hasOdd, int &oddElement);

    std::vector<size_t> generateJacobsthalIndices(size_t n);

    template <typename Container>
    void insertPetits(const Container &petits, Container &sorted);
};

#endif // PMERGEME_HPP
