#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "\033[38;2;255;140;0mWrongCat: \033[0m" << "WrongCat created!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "\033[38;2;255;140;0mWrongCat: \033[0m"<< "WrongCat deleted!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "Default assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

