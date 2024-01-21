#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char *av[]) {
	double d;
	double i_min = static_cast<double>(std::numeric_limits<int>::min());
	double i_max = static_cast<double>(std::numeric_limits<int>::max());

	for (int i = 1; i < ac; i++) {
		d = std::atof(av[i]);
		if (d < i_min || d > i_max || d <= 0)
			throw InvalidInputException();
		_vector.push_back(static_cast<unsigned int>(d));
		_deque.push_back(static_cast<unsigned int>(d));
	}

	std::cout << "Before: ";
	for (vectorIt it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &pmg) {
	_vector = pmg._vector;
	_deque = pmg._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmg) {
	if (this != &pmg) {
		_vector.clear();
		_vector = pmg._vector;
		_deque.clear();
		_deque = pmg._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::makeJacopsthal() {
	size_t i = 2;
	_jacobsthal.push_back(1);
	_jacobsthal.push_back(3);
	while (1) {
		_jacobsthal.push_back(_jacobsthal[i - 1] + 2 * _jacobsthal[i - 2]);
		if (_jacobsthal.back() > _vector.size())
			break;
		++i;
	}
}

size_t PmergeMe::getIndex(size_t idx) {
	if (idx < 2)
		return _jacobsthal[idx];
	if (idx - 1 == _jacobsthal[_jacobsthalIndex]) {
		_jacobsthalIndex++;
		return _jacobsthal[_jacobsthalIndex + 1];
	}
	return idx - 1;
}

void PmergeMe::vectorComparePair(size_t pairCount, size_t pairSize) {
	vectorIt start = _vector.begin();
	vectorIt first, second;

	for (size_t i = 0; i < pairCount - 1; i += 2) {
		first = start + i * pairSize;
		second = start + (i + 1) * pairSize;
		if (*first < *second)
			std::swap_ranges(first, second, second);
	}
}

void PmergeMe::vectorMakeChain(size_t pairCount,
															 size_t pairSize,
															 vector &mainChain,
															 vector &subChain) {
	vectorIt start = _vector.begin();
	for (size_t i = 0; i < pairCount; i++) {
		if (i == pairCount - 1 || i % 2)
			subChain.insert(subChain.end(),
											start + i * pairSize,
											start + (i + 1) * pairSize);
		else if (i % 2 == 0)
			mainChain.insert(mainChain.end(),
											 start + i * pairSize,
											 start + (i + 1) * pairSize);
	}
}

void PmergeMe::vectorBinaryInsertion(size_t idx,
																		 size_t pairSize,
																		 vector &mainChain,
																		 vector &subChain) {
	vectorIt subChainIt = subChain.begin() + idx * pairSize;
	vectorIt mainChainIt = mainChain.begin();
	if (idx == 0) {
		mainChain.insert(mainChainIt, subChainIt, subChainIt + pairSize);
		return;
	}

	// overflow 방지를 위해 int 사용
	int left = 0;
	int right = idx + _insertNum;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (mainChain[mid * pairSize] < *subChainIt)
			left = mid + 1;
		else
			right = mid - 1;
	}
	mainChain.insert(mainChainIt + left * pairSize,
									 subChainIt,
									 subChainIt + pairSize);
	_insertNum++;
}

void PmergeMe::vectorInsertion(size_t pairCount,
															 size_t pairSize,
															 vector &mainChain,
															 vector &subChain) {
	size_t idx = 0;
	_insertNum = 0;
	_jacobsthalIndex = 0;
	size_t subChainSize = pairCount / 2 + pairCount % 2;
	vectorMakeChain(pairCount, pairSize, mainChain, subChain);

	for (size_t i = 0; i < subChainSize; i++) {
		idx = std::min(getIndex(idx), subChainSize);
		vectorBinaryInsertion(idx - 1, pairSize, mainChain, subChain);
	}
	for (size_t i = 0; i < mainChain.size(); i++)
		_vector[i] = mainChain[i];
}

void PmergeMe::vectorMergeInsertion(size_t pairCount, size_t pairSize) {
	if (pairCount == 1)
		return;

	vector mainChain, subChain;
	vectorComparePair(pairCount, pairSize);
	vectorMergeInsertion(pairCount / 2, pairSize * 2);
	vectorInsertion(pairCount, pairSize, mainChain, subChain);
}

void PmergeMe::dequeComparePair(size_t pairCount, size_t pairSize) {
	dequeIt start = _deque.begin();
	dequeIt first, second;

	for (size_t i = 0; i < pairCount - 1; i += 2) {
		first = start + i * pairSize;
		second = start + (i + 1) * pairSize;
		if (*first < *second)
			std::swap_ranges(first, second, second);
	}
}

void PmergeMe::dequeMakeChain(size_t pairCount,
															size_t pairSize,
															deque &mainChain,
															deque &subChain) {
	dequeIt start = _deque.begin();

	for (size_t i = 0; i < pairCount - 1; i++) {
		if (i == pairCount - 1 || i % 2)
			subChain.insert(subChain.end(),
											start + i * pairSize,
											start + (i + 1) * pairSize);
		else if (i % 2 == 0)
			mainChain.insert(mainChain.end(),
											 start + i * pairSize,
											 start + (i + 1) * pairSize);
	}
}

void PmergeMe::dequeBinaryInsertion(size_t idx,
																		size_t pairSize,
																		deque &mainChain,
																		deque &subChain) {
	dequeIt subChainIt = subChain.begin() + idx * pairSize;
	dequeIt mainChainIt = mainChain.begin();
	if (idx == 0) {
		mainChain.insert(mainChainIt, subChainIt, subChainIt + pairSize);
		return;
	}

	// overflow 방지를 위해 int 사용
	int left = 0;
	int right = idx + _insertNum;
	while (left <= right) {
		int mid = (left + right) / 2;
		std::cout << "while start" << std::endl;
		if (mainChain[mid * pairSize] < *subChainIt)
			left = mid + 1;
		else
			right = mid - 1;
		std::cout << "while end" << std::endl;
	}
	std::cout << "before insert" << std::endl;
	mainChain.insert(mainChainIt + left * pairSize,
									 subChainIt,
									 subChainIt + pairSize);
	std::cout << "after insert" << std::endl;
	_insertNum++;
}

void PmergeMe::dequeInsertion(size_t pairCount,
															size_t pairSize,
															deque &mainChain,
															deque &subChain) {
	size_t idx = 0;
	_insertNum = 0;
	_jacobsthalIndex = 0;
	size_t subChainSize = pairCount / 2 + pairCount % 2;
	dequeMakeChain(pairCount, pairSize, mainChain, subChain);

	for (size_t i = 0; i < subChainSize; i++) {
		idx = std::min(getIndex(idx), subChainSize);
		dequeBinaryInsertion(idx - 1, pairSize, mainChain, subChain);
	}
	for (size_t i = 0; i < mainChain.size(); i++)
		_deque[i] = mainChain[i];
}

void PmergeMe::dequeMergeInsertion(size_t pairCount, size_t pairSize) {
	if (pairCount == 1)
		return;

	deque mainChain, subChain;
	dequeComparePair(pairCount, pairSize);
	dequeMergeInsertion(pairCount / 2, pairSize * 2);
	dequeInsertion(pairCount, pairSize, mainChain, subChain);
}

void PmergeMe::compareMergeInsertion() {
	size_t start, vectorTime, dequeTime;
	makeJacopsthal();

	start = clock();
	vectorMergeInsertion(_vector.size(), 1);
	vectorTime = clock() - start;

	start = clock();
	dequeMergeInsertion(_deque.size(), 1);
	dequeTime = clock() - start;

	std::cout << "After: ";
	for (vectorIt it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size()
						<< " elements with std::vector : " << vectorTime << " us"
						<< std::endl;
	std::cout << "Time to process a range of " << _deque.size()
						<< " elements with std::deque : " << dequeTime << " us"
						<< std::endl;
}