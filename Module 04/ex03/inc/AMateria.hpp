#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	private:
		
	protected:
		std::string const	_type;
	public:
		AMateria();
		AMateria(std::string& type);
		virtual ~AMateria();
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria& copy);
		virtual std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif