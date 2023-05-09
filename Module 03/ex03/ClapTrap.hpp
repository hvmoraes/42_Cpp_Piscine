#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#pragma once

#include <iostream>

class ClapTrap {
	protected:
		ClapTrap();
		std::string _name;
		int _hitPts;
		int _initHitPts;
		int _energyPts;
		int _attackDmg;
	public:
		ClapTrap(const std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif