#include "../inc/Animal.hpp"
#include "Brain.hpp"

Animal::Animal() {
	std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "Animal created!" << std::endl;
}

Animal::~Animal() {
	std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "Animal deleted!" << std::endl;
}

Animal::Animal(const Animal& copy) {
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy) {
	this->_type = copy._type;
	return(*this);
}

void Animal::makeSound() {
	if (this->_type == "Cat") {
		std::cout << "\033[38;2;70;130;180mCat:\033[0m " << "Miau" << std::endl;
	} else if (this->_type == "Dog") {
		std::cout << "\033[0;33mDog:\033[0m " << "Au Au" << std::endl; 
	} else {
		std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "Animal sounds" << std::endl;
	}
}

std::string Animal::getType() {
	return (this->_type);
}

void Animal::showIdeas() {
	std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "I don't have a brain, I can't have ideas" << std::endl;
}
