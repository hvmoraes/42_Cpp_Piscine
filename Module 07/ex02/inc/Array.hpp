#pragma once

#include <iostream>

#define print(x) std::cout << x << std::endl

template <class T>
class arrayClass {
	private:
		T *array;
		int _size;
	public:
		arrayClass() :   array(nullptr), _size(0) {};
		arrayClass(unsigned int n);
		arrayClass(const arrayClass &copy);
		~arrayClass() {
      delete[] array;
    }

		int size();

		T& operator[](int index);
		arrayClass& operator=(const arrayClass &copy);
};
