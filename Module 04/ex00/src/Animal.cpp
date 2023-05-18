#include "Animal.hpp"

Animal::Animal() {
	std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "Animal created!" << std::endl;
}

Animal::~Animal() {
	std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "Animal deleted!" << std::endl;
}

void Animal::makeSound() {
	if (this->_type == "Cat") {
		std::cout << "Miau" << std::endl;
	} else if (this->_type == "Dog") {
		std::cout << "\033[0;33mDog:\033[0m " << "Au Au" << std::endl; 
	} else {
		std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "Animal sounds" << std::endl;
	}
}

std::string Animal::getType() {
	return (this->_type);
}