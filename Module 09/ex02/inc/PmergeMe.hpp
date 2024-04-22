#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <bits/stdc++.h>

#define print(x) std::cout << x << std::endl
#define out std::cout
#define el std::endl

class PmergeMe {
	private:
		
	protected:
		
	public:
		int size;
		char **input;
		std::vector<int> vector;
		std::deque<int> deque;

		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);

		int	sort();

		// List
		void initVector();
		void sortVector();
		void sortPairVector();
		void sortPairsRecursiveVector(size_t size);

		// Deque
		void initDeque();
		void sortDeque();
		void sortPairDeque();
		void sortPairsRecursiveDeque(size_t size);

		// Utils
		int parse();
		void showInput();
		void showVector();
		void showDeque();
		void	convertTime(double duration);
		size_t  getJacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index);

		// Template Functions
		template <typename T>
		static size_t insertionIndex(T vd, int target)
		{
			int high = vd.size() - 1;
			int low = 0;
			while (low <= high)
			{
				size_t mid = std::floor((high + low) / 2);
				if (vd[mid] == target)
					return mid;
				else if (vd[mid] > target)
					high = mid - 1;
				else
					low = mid + 1;
			}
			return low;
		}

		// Inserts the pend vector in the main chain
		template <typename T>
		T    insertB(T &a, T &b)
		{
			size_t aux = 1;
			size_t f = 0;
			size_t smaller_index = 1;
			size_t jacob_order = 1;

			int index_b;
			while (f < b.size())
			{
				// Uses the jacobshtal number to get the index of the next element of b to insert in a
				aux = getJacobsthal(aux, &jacob_order, &smaller_index);
				while (aux > b.size())
						aux--;
				index_b = aux - 1;

				// Binary search and insertion of b in a
				size_t index = insertionIndex(a, b[index_b]);
				a.insert(a.begin() + index, b[index_b]);

				f++;
			}
			return (a);
		}

		// a main chain vector: high values of each pair
		// b pend elements vector: low values of each pair
		template <typename T>
		std::pair<T,T > getAB(T &vd)
		{
			T a;
			T b;
			typename T::iterator it = vd.begin();
			while (it + 1 != vd.end() && it != vd.end())
			{
				b.push_back(*it);
				a.push_back(*(it + 1));
				std::advance(it, 2);
			}
			if (it != vd.end())
				b.push_back(*it);
			return std::make_pair(a, b);
		}
};

#endif