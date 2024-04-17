#include "../inc/PmergeMe.hpp"

void PmergeMe::sortPairDeque()
{
	for (size_t i = 0; i + 1 < deque.size(); i += 2) {
		if (this->deque[i + 1] && deque[i] > deque[i + 1])
			std::swap(deque[i], deque[i + 1]);
	}
}

void PmergeMe::sortPairsRecursiveDeque(size_t size)
{
	if (size >= deque.size())
		return ;
	for (size_t i = 1; i < deque.size() - 1; i += 2) {
        if (deque[i] > deque[size]) {
			std::swap(deque[i], deque[size]);
			std::swap(deque[i - 1], deque[size - 1]);
		}
	}
	sortPairsRecursiveDeque(size + 2);
}

void PmergeMe::sortDeque() {
	// sort each pair
	this->sortPairDeque();

	int odd = 0;
	int last = deque[deque.size() - 1];
	if (deque.size() % 2 != 0) {
		odd = 1;
		deque.erase(deque.end() - 1);
	}

	// sort pairs recursively (according to highest value)
	sortPairsRecursiveDeque(1);

	if (odd == 1)
		deque.insert(deque.end(), last);
	
	std::pair<std::deque<int>,std::deque<int> > ab = getAB(deque);
	std::deque<int> final_deque = PmergeMe::insertB(ab.first, ab.second);
	this->deque = final_deque;
}