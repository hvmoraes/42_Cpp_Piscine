#include "../inc/easyfind.hpp"
#include "easyfind.tpp"

int main() {
	int ints[] = {1, 5, 2, 7, 10, -20, -8, 0, 5};
	std::vector<int> vector(ints, ints + sizeof(ints) / sizeof(int));
	std::deque<int> deque(ints, ints + sizeof(ints) / sizeof(int));
	std::list<int> list(ints, ints + sizeof(ints) / sizeof(int));
	
	try {
		::easyfind(vector, 6);
	}
	catch(const notFoundException& e) {
		std::cout << e.what() << '\n';
	}
	::easyfind(deque, 5);
	::easyfind(list, -8);
}