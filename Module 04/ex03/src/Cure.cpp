#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/IMateriaSource.hpp"

Cure::Cure(): _type("cure") {
	std::cout << "\033[38;2;0;100;0mCure:\033[0m " << this->_type << " constructed" << std::endl;
}

Cure::~Cure() {
	std::cout << "\033[38;2;0;100;0mCure:\033[0m " << this->_type << " destroyed" << std::endl;
}

Cure::Cure(const Cure& copy) {
	std::cout << "\033[38;2;0;100;0mCure:\033[0m " << this->_type << " constructed from copy" << std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure& copy) {
	std::cout << "\033[38;2;0;100;0mCure:\033[0m " << "assigned from " << copy.getType() << std::endl;
	(void)copy;	return (*this);
}

std::string const& Cure::getType() const {
	return (this->_type);
}

Cure *Cure::clone() const {
	Cure	*result = new Cure;
	return (result);
}

void Cure::use(ICharacter& target) {
	std::string target_name = target.getName();
	std::cout << " heals " << target_name << "\'s wounds" << std::endl;
}
