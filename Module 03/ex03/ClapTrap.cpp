#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPts(10), _initHitPts(10), _energyPts(10), _attackDmg(0) {
}

ClapTrap::ClapTrap() : _name(""), _hitPts(10), _initHitPts(10), _energyPts(10), _attackDmg(0) {
}

ClapTrap::~ClapTrap() {
}

void ClapTrap::attack(const std::string& target) {
	if (this->_energyPts <= 0) {
		std::cout << "\033[38;2;11;98;164mClapTrap\033[0m " << this->_name << " doesn't have more energy, he can't attack..." << std::endl;
	} else if (this->_hitPts <= 0) {
		std::cout << "\033[38;2;11;98;164mClapTrap\033[0m " << this->_name << " is dead... he can't attack!" << std::endl;
	} else {
		std::cout << "\033[38;2;11;98;164mClapTrap\033[0m " << this->_name << " \033[1;31mattacks\033[0m " << target << ", causing " << this->_attackDmg << " damage!" << std::endl;
		this->_energyPts--;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPts <= 0) {
		std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " doesn't have more energy, he can't be repaired..." << std::endl;
	} else if (this->_hitPts <= 0) {
		std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " is dead... he can't be repaired!" << std::endl;
	} else if (this->_hitPts >= this->_initHitPts) {
		std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " is at maximum health... he can't be repaired!" << std::endl;
	}  else {
		std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " \033[1;33mrepairs\033[0m itself with " << amount << " hit points!" << std::endl;
		this->_hitPts += amount;
		this->_energyPts--;
		std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " now has " << this->_hitPts << " hit points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPts <= 0) {
		std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " is dead... he can't take more damage!" << std::endl;
	} else {
		this->_hitPts -= amount;
		if (this->_hitPts <= 0) {
			std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " suffered " << amount << " damage!" << std::endl;
			std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " died!" << std::endl;
		} else {
			this->_energyPts--;
			std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " suffered " << amount << " damage!" << std::endl;
			std::cout << "\033[1;34mClapTrap\033[0m " << this->_name << " now has " << this->_hitPts << " hit points." << std::endl;
		} 
	}
}