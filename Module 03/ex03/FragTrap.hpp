#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		FragTrap();
	public:
		FragTrap(const std::string &name);
		~FragTrap();
		void highFivesGuys(void);
};

#endif