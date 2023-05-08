#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "\033[38;2;76;187;23mFragTrap\033[0m " << this->_name << " created!" << std::endl;
	this->_attackDmg = 30;
	this->_energyPts = 100;
	this->_hitPts = 100;
}

FragTrap::FragTrap() {
	this->_attackDmg = 30;
	this->_energyPts = 100;
	this->_hitPts = 100;
}

FragTrap::~FragTrap() {
	std::cout << "\033[38;2;76;187;23mFragTrap\033[0m " << this->_name << " died..." << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "\033[38;2;76;187;23mFragTrap\033[0m "<< this->_name << " is asking for a high five guys!!" << std::endl;
}