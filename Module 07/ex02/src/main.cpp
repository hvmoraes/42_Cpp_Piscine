#include "../inc/Array.hpp"
#include "Array.tpp"

int main() {
	unsigned int n = 5;

	arrayClass<int> intArray(n);
	arrayClass<std::string> stringArray(4);
	arrayClass<int> intArrayCopy(intArray);

	try {
		intArray[5] = 4;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	stringArray[1] = "Hello World!";
	intArray[2] = 3;
	intArray[4] = 2;
	intArrayCopy[1] = 5;

	print(stringArray[1]);
	print(stringArray.size());
	print(intArray[2]);
	print(intArrayCopy[2]);
	print(intArray[1]);
	print(intArrayCopy[1]);

	return (0);
}
