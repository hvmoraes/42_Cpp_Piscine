#include "../inc/easyfind.hpp"

template <typename T>
void easyfind(const T& array, int find) {
	if (std::find(array.begin(), array.end(), find) != array.end()) {
		std::cout << "Found " << find << " at index " << std::distance(array.begin(), std::find(array.begin(), array.end(), find))  << std::endl;
	}
	else {
		std::cout << find << " ";
		throw(notFoundException());
	}
}