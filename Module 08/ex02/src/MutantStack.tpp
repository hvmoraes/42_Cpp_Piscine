#include "../inc/MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++() { // ++it
	this->current++;
	return (*this); 
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int) { // it++
	iterator temp = *this;
	++this->current;
	return temp;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--() { //--it
	this->current--;
	return (*this); 
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int) { // it--
	iterator temp = *this;
	--this->current;
	return temp;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &other) {
	return current != other.current;
}

template <typename T>
T &MutantStack<T>::iterator::operator*() {
	return (current);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	MutantStack<T>::iterator it;
	it.current = 0;
	return (it);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	MutantStack<T>::iterator it;
	it.current = this->size();
	return (it);
}