#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria {
	private:
		std::string _type;
	protected:
		
	public:
		Cure();
		~Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		std::string const& getType() const;
		Cure *clone() const;
		void use(ICharacter& target);
};

#endif