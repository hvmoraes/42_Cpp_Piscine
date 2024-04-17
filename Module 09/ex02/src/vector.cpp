#include "../inc/PmergeMe.hpp"

void    PmergeMe::sortPairVector()
{
	for (size_t i = 0; i + 1 < vector.size(); i += 2)
	{
		if (this->vector[i + 1] && this->vector[i] > this->vector[i + 1])
			iter_swap(vector.begin() + i, vector.begin() + i + 1);
	}
}

// recursive function to sort pairs
void	PmergeMe::sortPairsRecursiveVector(size_t size)
{
	if (size >= vector.size())
		return ;
	for (size_t i = 1; i < vector.size() - 1; i+=2) {
		if (vector[i] > vector[size]) {
			std::swap(vector[i], vector[size]);
			std::swap(vector[i - 1], vector[size - 1]);
		}
	}
	sortPairsRecursiveVector(size + 2);
}

void    PmergeMe::sortVector()
{
	// sort each pair
	this->sortPairVector();

	int odd = 0;
	int last = vector[vector.size() - 1];
	if (vector.size() % 2 != 0)
	{
		odd = 1;
		vector.erase(vector.end() - 1);
	}

	// sort pairs recursively (according to highest value)
	sortPairsRecursiveVector(1);

	if (odd == 1)
		vector.insert(vector.end(), last);

	std::pair<std::vector<int>,std::vector<int> > ab = getAB(vector);
	std::vector<int> vector = PmergeMe::insertB(ab.first, ab.second);
	this->vector = vector;
}