#include "../inc/easyfind.hpp"

template <typename T>
int easyfind(const T& array, int find) {
	auto f = std::find(array.begin(), array.end(), find);
	if (f != array.end()) {
		return(std::distance(array.begin(), f));
	}
	//throw(something);
	return (-1);
}
