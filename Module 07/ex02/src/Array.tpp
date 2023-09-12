#pragma once

#include "../inc/Array.hpp"

template <class T>
arrayClass<T>::arrayClass(unsigned int n) : array(new T[n]), _size(n) {
	for (unsigned int i = 0; i < n; i++)
		array[i] = T();
}

template <class T>
arrayClass<T>::arrayClass(const arrayClass& copy) : array(new T[copy._size]), _size(copy._size) {
	print("Copy constructor called!");
	for (int i = 0; i < _size; i++) {
		array[i] = copy.array[i];
	}
}

template <class T>
int arrayClass<T>::size() {
	return (_size);
}

template <class T>
T& arrayClass<T>::operator[](int i) {
	if (i < 0 || i >= size()) {
		throw std::out_of_range("Index out of bounds!");
	}
	return array[i];
}

template <class T>
arrayClass<T>& arrayClass<T>::operator=(const arrayClass& copy) {
	print("Assignement operator called!");
	if (this != &copy) {
		delete[] array;
		_size = copy._size;
		array = new T[_size];
		for (int i = 0; i < _size; i++) {
			array[i] = copy.array[i];
		}
	}
	return (*this);
}
