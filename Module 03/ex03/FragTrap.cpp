#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	this->_name = name;
	this->_attackDmg = 30;
	this->_energyPts = 100;
	this->_hitPts = 100;
	this->_initHitPts = this->_hitPts;
	std:: cout << this->_attackDmg << std::endl;
}

FragTrap::FragTrap() : ClapTrap() {
	this->_name = "";
	this->_attackDmg = 30;
	this->_energyPts = 100;
	this->_hitPts = 100;
	this->_initHitPts = this->_hitPts;
}

FragTrap::~FragTrap() {

}

void FragTrap::highFivesGuys() {
	std::cout << "\033[38;2;76;187;23mFragTrap\033[0m "<< this->_name << " is asking for a high five guys!!" << std::endl;
}