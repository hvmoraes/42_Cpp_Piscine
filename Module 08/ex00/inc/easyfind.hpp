#pragma once

#include <iostream>
#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <list>

template <typename T>
void easyfind(const T& array, int find);

class notFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("not found");
		};
};