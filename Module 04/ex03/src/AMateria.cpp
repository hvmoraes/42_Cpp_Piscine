#include "../inc/AMateria.hpp"

AMateria::AMateria() {
	std::cout << "\033[38;2;240;230;140mAbstract Materia:\033[0m" << " abstract materia has beed created" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "\033[38;2;240;230;140mAbstract Materia:\033[0m abstract materia has beed destroyed" << std::endl;
}

AMateria::AMateria(const AMateria& copy): _type(copy._type) {
	std::cout << "\033[38;2;240;230;140mAbstract Materia:\033[0m abstract materia has beed constructed from a copy" << std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy) {
	std::cout << "\033[38;2;240;230;140mAbstract Materia:\033[0m default assignment operator called" << std::endl;
	(void)copy;	return (*this);
}

std::string const& AMateria::getType() const {
	return(this->_type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "\033[38;2;240;230;140mAbstract Materia:\033[0m AMateria abstractly used on " << target.getName() << std::endl;
}
