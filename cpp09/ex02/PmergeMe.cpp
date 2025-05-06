#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

PmergeMe::PmergeMe(char **argv)
{
    for (int i = 1; argv[i]; ++i)
    {
        int num = std::atoi(argv[i]);
        if (num < 0)
            throw std::invalid_argument("Negative numbers are not allowed.");
        _numbers.push_back(num);
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

void PmergeMe::printNumbers() const
{
    for (size_t i = 0; i < _numbers.size(); ++i)
        std::cout << _numbers[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::sortPairs(const std::vector<int> &tab,
                         std::vector<std::pair<int, int> > &pairs,
                         bool &hasOdd,
                         int &oddElement)
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

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n)
{
    std::vector<size_t> indices;
    std::vector<size_t> jacob;

    jacob.push_back(0);
    jacob.push_back(1);
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

void PmergeMe::insertPetits(const std::vector<int> &petits, std::vector<int> &sorted)
{
    std::vector<size_t> order = generateJacobsthalIndices(petits.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t idx = order[i];
        if (idx >= petits.size())
            continue;

        int value = petits[idx];
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
        sorted.insert(pos, value);
    }
}

void PmergeMe::fordJohnsonSort(std::vector<int> &tab)
{
    if (tab.size() <= 1)
        return;

    bool hasOdd;
    int oddElement;
    std::vector<std::pair<int, int> > pairs;

    sortPairs(tab, pairs, hasOdd, oddElement);

    std::vector<int> petits, grands;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        petits.push_back(pairs[i].first);
        grands.push_back(pairs[i].second);
    }

    fordJohnsonSort(grands);

    std::vector<int> sorted = grands;
    insertPetits(petits, sorted);

    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), oddElement);
        sorted.insert(pos, oddElement);
    }

    tab = sorted;

    if (tab.size() == _numbers.size()) // Affiche uniquement à l’appel initial
    {
        std::cout << "Paires (min,max) : ";
        for (size_t i = 0; i < pairs.size(); ++i)
            std::cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
        std::cout << std::endl;
    }
}

void PmergeMe::sort()
{
    printNumbers(); // Avant tri
    fordJohnsonSort(_numbers);
    printNumbers(); // Après tri
}
