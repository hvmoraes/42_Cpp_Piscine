#include "../inc/iter.hpp"

void intFunc(int *nbr) {
	*nbr *= 2;
	print(*nbr);
}

void stringFunc(std::string *string) {
	*string = "New String";
	print(*string);
}

int main() {
	int intVector[5] = {1, 2, 3, 4, 5};
	std::string stringVector[5] = {"One", "Word", "Is", "Not", "Enough"};
	::iter(intVector, sizeof(intVector) / sizeof(int), &intFunc);
	::iter(stringVector, sizeof(stringVector) / sizeof(std::string), &stringFunc);
	return (0);
}