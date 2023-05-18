#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria {
	private:
		std::string _type;
	protected:
		
	public:
		Ice();
		~Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		std::string const& getType() const;
		Ice *clone() const;
		void use(ICharacter& target);
};

#endif