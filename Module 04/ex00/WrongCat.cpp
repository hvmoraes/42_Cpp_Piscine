#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "\033[38;2;255;140;0mWrongCat: \033[0m" << "WrongCat created!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "\033[38;2;255;140;0mWrongCat: \033[0m"<< "WrongCat deleted!" << std::endl;
}