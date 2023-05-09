#include "Cat.hpp"

Cat::Cat() {
	std::cout << "\033[38;2;70;130;180mCat: \033[0m" << "Cat created!" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat() {
	std::cout << "\033[38;2;70;130;180mCat: \033[0m" << "Cat deleted!" << std::endl;
}