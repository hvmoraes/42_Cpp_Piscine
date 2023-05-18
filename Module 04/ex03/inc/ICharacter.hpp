#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#pragma once

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter {
	private:
		
	protected:
		std::string const _name;
	public:
		virtual ~ICharacter() {}
		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* materia) = 0;
		virtual void unequip(int index) = 0;
		virtual void use(int index, ICharacter& target) = 0;
};

#endif