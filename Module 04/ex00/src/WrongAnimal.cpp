#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "\033[38;2;85;107;47mWrongAnimal:\033[0m " << "WrongAnimal created!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "\033[38;2;85;107;47mWrongAnimal:\033[0m " << "WrongAnimal deleted!" << std::endl;
}

void WrongAnimal::makeSound() {
	std::cout << "\033[38;2;85;107;47mWrongAnimal:\033[0m " << "WrongAnimal sounds" << std::endl;

}

std::string WrongAnimal::getType() {
	return (this->_type);
}