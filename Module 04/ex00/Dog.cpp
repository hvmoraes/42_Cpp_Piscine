#include "Dog.hpp"

Dog::Dog() {
	std::cout << "\033[0;33mDog:\033[0m " << "Dog created!" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog() {
	std::cout << "\033[0;33mDog:\033[0m " << "Dog deleted!" << std::endl;
}