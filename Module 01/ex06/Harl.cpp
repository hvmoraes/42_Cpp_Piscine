#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
		std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
		std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level) {
	std::string compT(level.length(), ' ');
	for (size_t i = 0; i < level.length(); i++) {
		compT[i] = tolower(level[i]);
	}

	void	(Harl::*comp[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	msg[4] = {"debug", "info", "warning", "error"};
	size_t index = -1;
	for (int i = 0; i < 4; i++) {
		if (msg[i] == compT) {
			index = i;
		}
	}

	switch (index)
	{
	case (0):
		for (int i = index; i < 4; i++)
			(this->*(comp[i]))();
		break;
	case (1):
		for (int i = index; i < 4; i++)
		  (this->*(comp[i]))();
		break;
	case (2):
		for (int i = index; i < 4; i++)
			(this->*(comp[i]))();
		break;
	case (3):
		for (int i = index; i < 4; i++)
	  		(this->*(comp[i]))();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}	
}