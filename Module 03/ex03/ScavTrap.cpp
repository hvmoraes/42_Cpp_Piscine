#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "\033[38;2;201;255;99mScavTrap\033[0m " << this->_name << " created!" << std::endl;
	this->_attackDmg = 20;
	this->_energyPts = 50;
	this->_hitPts = 100;
}

ScavTrap::ScavTrap() {
	this->_attackDmg = 20;
	this->_energyPts = 50;
	this->_hitPts = 100;
}

ScavTrap::~ScavTrap() {
	std::cout << "\033[38;2;201;255;99mScavTrap\033[0m " << this->_name << " died..." << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "\033[38;2;201;255;99mScavTrap\033[0m " << this->_name << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energyPts <= 0) {
		std::cout << "\033[38;2;201;255;99mScavTrap\033[0m " << this->_name << " doesn't have more energy, he can't attack..." << std::endl;
	} else if (this->_hitPts <= 0) {
		std::cout << "\033[38;2;201;255;99mScavTrap\033[0m " << this->_name << " is dead... he can't attack!" << std::endl;
	} else {
		std::cout << "\033[38;2;201;255;99mScavTrap\033[0m " << this->_name << " \033[1;31mattacks\033[0m " << target << ", causing " << this->_attackDmg << " damage!" << std::endl;
		this->_energyPts--;
	}
}