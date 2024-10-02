#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <limits>
#include <deque>
#include <vector>
#include <cstdlib>

typedef std::deque<unsigned int> deque;
typedef std::vector<unsigned int> vector;
typedef std::deque<unsigned int>::iterator dequeIt;
typedef std::vector<unsigned int>::iterator vectorIt;

class PmergeMe {
private:
    int _insertNum;
    int _jacobsthalIndex;

    deque _deque;
    vector _vector;
    vector _jacobsthal;

    PmergeMe();
    PmergeMe(const PmergeMe &pmg);
    PmergeMe &operator=(const PmergeMe &pmg);

    void makeJacopsthal();
    size_t getInsertPos(size_t insertPos);

    void vectorMergeInsertion(size_t pairCount, size_t pairSize);
    void vectorComparePair(size_t pairCount, size_t pairSize);
    void vectorInsertion(size_t pairCount, size_t pairSize);
    void vectorMakeChain(size_t pairCount,
                         size_t pairSize,
                         vector &mainChain,
                         vector &subChain);
    void vectorBinaryInsertion(size_t idx,
                               size_t pairSize,
                               vector &mainChain,
                               vector &subChain);

    void dequeMergeInsertion(size_t pairCount, size_t pairSize);
    void dequeComparePair(size_t pairCount, size_t pairSize);
    void dequeInsertion(size_t pairCount, size_t pairSize);
    void dequeMakeChain(size_t pairCount,
                        size_t pairSize,
                        deque &mainChain,
                        deque &subChain);
    void dequeBinaryInsertion(size_t pairCount,
                              size_t pairSize,
                              deque &mainChain,
                              deque &subChain);

public:
    PmergeMe(int ac, char *av[]);
    ~PmergeMe();

    void compareMergeInsertion();
};

#endif
