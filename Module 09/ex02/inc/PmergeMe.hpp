#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <deque>
#include <chrono>

#define print(x) std::cout << x << std::endl
#define out std::cout
#define el std::endl

class PmergeMe {
	private:
		
	protected:
		
	public:
		int size;
		char **input;
		std::list<int> list;
		std::deque<int> deque;

		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& copy);

		int	sort();
		int parse();
		void initList();
		void sortList(std::list<int>& list);
		void showList();
		void initDeque();
		void sortDeque(std::deque<int>& deque);
		void showDeque();
		void showInput();
};

#endif