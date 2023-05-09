#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) {
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 30;
	std::cout << "\033[38;2;0;191;255mDiamondTrap\033[0m " << this->_name << " created! It has " << this->_hitPts << " hit points, " << this->_energyPts << " energy points and " << this->_attackDmg << " attack damage." << std::endl;
}

DiamondTrap::DiamondTrap() {
	this->_hitPts = FragTrap::_hitPts;
	this->_energyPts = ScavTrap::_energyPts;
	this->_attackDmg = FragTrap::_attackDmg;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "\033[38;2;0;191;255mDiamondTrap\033[0m " << this->_name << " died..." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "\033[38;2;0;191;255mDiamondTrap\033[0m my name is " << this->_name << " and my ClapTrap's name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}