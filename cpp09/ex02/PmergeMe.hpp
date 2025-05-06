#include <vector>
#include <utility>
#include <cstdio>

class PmergeMe
{
public:
    PmergeMe(char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    void sort();
private:
    std::vector<std::pair<int, int> > _pairs;
    std::vector<int> _numbers;
    void printNumbers() const;
    void sortPairs(std::vector<int> &tab, std::vector<std::pair<int, int> > &pairs, bool& impair, int &elementImpair);
    void mergePairs(std::vector<std::pair<int, int> >& pairs);
    std::vector<size_t> generateJacobsthalIndices(size_t n);
    void insertPetits(const std::vector<int> &petits, std::vector<int> &sorted);
    void fordJohnsonSort(std::vector<int>& tab);
};