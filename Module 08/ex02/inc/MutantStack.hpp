#pragma once

#include <stack>
#include <iostream>

#define print(x) std::cout << x << std::endl

template <typename T>
class	MutantStack : public std::stack<T> {
	public:
		class iterator {
			public:
				int current;
				iterator& operator++();
				iterator operator++(int);
				iterator& operator--();
				iterator operator--(int);
				bool operator!=(const iterator &other);
				T &operator*();
		};
		iterator begin();
		iterator end();
};