#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template <typename T>
void easyfind(const T& array, int find);

class notFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("not found");
		};
};