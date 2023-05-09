#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string _name;
		DiamondTrap();
	public:
		DiamondTrap(const std::string &name);
		~DiamondTrap();
		void whoAmI();
		void attack(const std::string& target);
};

#endif