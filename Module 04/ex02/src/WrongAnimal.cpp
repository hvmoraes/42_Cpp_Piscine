#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "\033[38;2;85;107;47mWrongAnimal:\033[0m " << "WrongAnimal created!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "\033[38;2;85;107;47mWrongAnimal:\033[0m " << "WrongAnimal deleted!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << "Default assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

void WrongAnimal::makeSound() {
	std::cout << "\033[38;2;85;107;47mWrongAnimal:\033[0m " << "WrongAnimal sounds" << std::endl;
}

std::string WrongAnimal::getType() {
	return (this->_type);
}