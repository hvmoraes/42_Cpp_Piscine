#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		ScavTrap();
	public:
		ScavTrap(const std::string &name);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
};

#endif