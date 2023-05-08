#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "\033[1;37mFragTrap\033[0m " << this->_name << " created!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "\033[1;37mFragTrap\033[0m " << this->_name << " died..." << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "\033[1;37mFragTrap\033[0m "<< this->_name << " is asking for a high five guys!!" << std::endl;
}