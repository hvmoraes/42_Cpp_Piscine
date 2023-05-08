#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap();
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
};

#endif