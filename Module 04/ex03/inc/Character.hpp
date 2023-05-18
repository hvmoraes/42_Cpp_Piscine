#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		AMateria* (_inventory[4]);
		std::string	const _name;
	protected:
		
	public:
		Character(std::string name);
		~Character();
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		std::string const& getName() const;
		void equip(AMateria* materia);
		void unequip(int index);
		void use(int index, ICharacter& target);
		AMateria* getMateria(int index);
};

#endif