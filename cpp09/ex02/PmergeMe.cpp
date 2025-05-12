#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>
#include <climits>
#include <cerrno>
#include <cstdlib>

PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; ++i)
    {
        char *endptr;
        errno = 0;
        long num = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0')
            throw std::invalid_argument("Not a valid integer.");
        if (errno == ERANGE || num > INT_MAX || num < 0)
            throw std::out_of_range("Input out of range or negative.");

        _numbers.push_back(static_cast<int>(num));
    }
}


PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _numbers(other._numbers) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
        _numbers = other._numbers;
    return *this;
}

void PmergeMe::printSequence(const std::vector<int> &seq) const
{
    for (size_t i = 0; i < seq.size(); ++i)
        std::cout << seq[i] << " ";
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n)
{
    std::vector<size_t> indices;
    std::vector<size_t> jacob(2, 1);
    jacob[0] = 0;

    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

    for (size_t i = jacob.size(); i-- > 0;)
        if (jacob[i] < n && std::find(indices.begin(), indices.end(), jacob[i]) == indices.end())
            indices.push_back(jacob[i]);

    for (size_t i = 0; i < n; ++i)
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);

    return indices;
}

template <typename Container>
void PmergeMe::sortPairs(const Container &tab, std::vector<std::pair<int, int> > &pairs, bool &hasOdd, int &oddElement)
{
    size_t size = tab.size();
    hasOdd = (size % 2 != 0);
    size_t limit = hasOdd ? size - 1 : size;

    for (size_t i = 0; i < limit; i += 2)
    {
        int a = tab[i];
        int b = tab[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (hasOdd)
        oddElement = tab[size - 1];
}

template <typename Container>
void PmergeMe::insertPetits(const Container &petits, Container &sorted)
{
    std::vector<size_t> order = generateJacobsthalIndices(petits.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        if (idx >= petits.size())
            continue;

        int value = petits[idx];
        typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
        sorted.insert(pos, value);
    }
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &tab)
{
    if (tab.size() <= 1)
        return;

    bool hasOdd;
    int oddElement;
    std::vector<std::pair<int, int> > pairs;
    sortPairs(tab, pairs, hasOdd, oddElement);

    Container petits, grands;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        petits.push_back(pairs[i].first);
        grands.push_back(pairs[i].second);
    }

    fordJohnsonSort(grands);

    Container sorted = grands;
    insertPetits(petits, sorted);

    if (hasOdd)
    {
        typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), oddElement);
        sorted.insert(pos, oddElement);
    }

    tab = sorted;
}

void PmergeMe::sortAndCompare()
{
    std::vector<int> vec = _numbers;
    std::deque<int> deq(_numbers.begin(), _numbers.end());

    std::cout << "Before: ";
    printSequence(_numbers);

    timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonSort(vec);
    gettimeofday(&end, NULL);
    double vecTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    fordJohnsonSort(deq);
    gettimeofday(&end, NULL);
    double deqTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    std::cout << "After:  ";
    printSequence(vec);

    std::cout << "Time to process a range of " << _numbers.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _numbers.size()
              << " elements with std::deque  : " << deqTime << " us" << std::endl;
}
