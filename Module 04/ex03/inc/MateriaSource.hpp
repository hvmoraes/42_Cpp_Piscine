#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria *(_inventory[4]);
	protected:
		
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& copy);
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const& type);
};

#endif