#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define print(x) std::cout << x << std::endl

template <typename minTest>
minTest min(minTest a, minTest b) {
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename maxTest>
maxTest max(maxTest a, maxTest b) {
	if (a > b)
		return (a);
	else
		return (b);
}

template <typename swapTest>
void swap(swapTest *a, swapTest *b) {
	swapTest c;
	c = *a;
	*a = *b;
	*b = c;
}

#endif