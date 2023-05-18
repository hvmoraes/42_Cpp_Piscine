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
	
}

std::string Animal::getType() {
	return (this->_type);
}

void Animal::showIdeas() {
	std::cout << "\033[38;2;46;139;87mAnimal:\033[0m " << "I don't have a brain, I can't have ideas" << std::endl;
}
