#include "../inc/Ice.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/IMateriaSource.hpp"

Ice::Ice():  _type("ice") {
	std::cout << "\033[38;2;0;191;255mIce\033[0m " << this->_type << " constructed" << std::endl;
}

Ice::~Ice() {
	std::cout << "\033[38;2;0;191;255mIce\033[0m " << this->_type << " destroyed" << std::endl;
}

Ice::Ice(const Ice& copy): _type(copy.getType()) {
	std::cout << "\033[38;2;0;191;255mIce\033[0m " << this->_type << " constructed from copy" << std::endl;
}

Ice& Ice::operator=(const Ice& copy) {
	std::cout << "\033[38;2;0;191;255mIce\033[0m " << "assigned from " << copy.getType() << std::endl;
	(void)copy;
	return (*this);
}

std::string const& Ice::getType( void ) const {
	return (this->_type);
}

Ice *Ice::clone() const {
	Ice	*ret = new Ice;
	return (ret);
}

void Ice::use(ICharacter& target) {
	std::string target_name = target.getName();
	std::cout << " shoots an ice bolt at " << target_name << std::endl;
}

