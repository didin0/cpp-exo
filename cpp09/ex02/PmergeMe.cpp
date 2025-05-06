#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <utility>

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

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other) : _numbers(other._numbers)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
    }
    return *this;
}

void PmergeMe::printNumbers() const
{
    for (size_t i = 0; i < _numbers.size(); ++i)
    {
        std::cout << _numbers[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortPairs(std::vector<int> &tab, std::vector<std::pair<int, int> > &pairs, bool &impair, int &elementImpair)
{
    size_t size = tab.size();
    impair = (size % 2 != 0);
    size_t limit = impair ? size - 1 : size;

    for (size_t i = 0; i < limit; i += 2)
    {
        int a = tab[i];
        int b = tab[i + 1];
        if (a > b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
    }

    if (impair)
        elementImpair = tab[size - 1];
}

void PmergeMe::mergePairs(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i + 1 < pairs.size(); ++i)
    {
        // Compare le dernier élément de la paire actuelle avec le premier élément de la paire suivante
        if (pairs[i].second > pairs[i + 1].first)
        {
            std::swap(pairs[i].second, pairs[i + 1].first);
        }
    }
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    std::vector<size_t> indices;
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (jacobsthal.back() < n) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }

    // Ajout sans doublons
    for (size_t i = jacobsthal.size() - 1; i > 0; --i) {
        if (jacobsthal[i] < n && jacobsthal[i] != 0 &&
            std::find(indices.begin(), indices.end(), jacobsthal[i]) == indices.end())
        {
            indices.push_back(jacobsthal[i]);
        }
    }

    // Ajouter les indices manquants
    for (size_t i = 1; i < n; ++i) {
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);
    }

    return indices;
}



void PmergeMe::insertPetits(const std::vector<int> &petits, std::vector<int> &sorted)
{
    if (petits.empty())
        return;

    // Insère d'abord petits[0] pour initialiser
    std::vector<int>::iterator pos0 = std::lower_bound(sorted.begin(), sorted.end(), petits[0]);
    sorted.insert(pos0, petits[0]);

    // Génère l’ordre Jacobsthal pour les suivants
    std::vector<size_t> insertionOrder = generateJacobsthalIndices(petits.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t idx = insertionOrder[i];
        if (idx >= petits.size())
            continue;

        int value = petits[idx];
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
        sorted.insert(pos, value);
    }

    // Debugging output
    std::cout << "Ordre d'insertion Jacobsthal : ";
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        std::cout << insertionOrder[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Petits : ";
    for (size_t i = 0; i < petits.size(); ++i) {
        std::cout << petits[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Tableau trié après insertion : ";
    for (size_t i = 0; i < sorted.size(); ++i) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::fordJohnsonSort(std::vector<int>& tab)
{
    if (tab.size() <= 1)
        return;

    bool impair;
    int elementImpair;
    std::vector<std::pair<int, int> > pairs;

    // Étape 1 : créer les paires (min, max)
    sortPairs(tab, pairs, impair, elementImpair);

    std::vector<int> petits;
    std::vector<int> grands;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        petits.push_back(pairs[i].first);
        grands.push_back(pairs[i].second);
    }

    // Étape 2 : tri récursif des grands
    fordJohnsonSort(grands);

    // Étape 3 : insertion des petits
    std::vector<int> sorted = grands;
    insertPetits(petits, sorted);

    // Étape 4 : élément impair
    if (impair) {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), elementImpair);
        sorted.insert(pos, elementImpair);
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
    printNumbers();
    std::vector<int> sorted = _numbers;
    fordJohnsonSort(sorted);
    _numbers = sorted;
    printNumbers();
}


