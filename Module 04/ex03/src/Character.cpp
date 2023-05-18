#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"

Character::Character(std::string name): _name(name) {
	std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << _name << " was created" << std::endl;
	for(int i = 0; i < 4; i++) {
		(this->_inventory)[i] = 0;
	}
}

Character::~Character() {
	std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << this->_name << " was destroyed" << std::endl;
	for (int i = 0; i < 4; i++) {
		if ((this->_inventory)[i]) {
			delete ((this->_inventory)[i]);
		}
	}
}

Character::Character(const Character& copy):  _name(copy.getName() + "_copy") {
	std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << _name << " was created from copy of " << copy._name << std::endl;
	for(int i = 0; i < 4; i++) {
		if ((copy._inventory)[i])
			(this->_inventory)[i] = ((copy._inventory)[i])->clone();
		else
			(this->_inventory)[i] = 0;
	}
}

Character& Character::operator=(const Character& copy) {
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = (copy._inventory[i])->clone();
	}
	return (*this);
}

std::string const& Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* materia) {
	int i = 0;

	if (!materia) {
		std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << this->_name << " tried to equip an invalid materia" << std::endl;
		return ;
	}
	while ((this->_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4) {
		std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << this->_name << " can't equip more than 4 Materia" << std::endl;
		return ;
	}
	(this->_inventory)[i] = materia;
	std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << this->_name << " equipped materia " << materia->getType() << " in slot " << i << "" << std::endl;
}

void Character::unequip(int index) {
	if (index < 0 || index >= 4)
		std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << this->_name << " tried to unequip nothing at invalid slot slot " << index << std::endl;
	else if (!(this->_inventory)[index])
		std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << this->_name << " has nothing equipped at slot " << index << " so he can't unequip it" << std::endl;
	else {
		AMateria *ptr = (this->_inventory)[index];
		std::cout << "\033[38;2;0;0;139mCharacter:\033[0m " << this->_name << " unequipped " << ptr->getType() << " at slot "<< index << "" << std::endl;
		(this->_inventory)[index] = 0;
	}
}

void Character::use(int index, ICharacter& target) {
	std::cout << "\033[38;2;0;0;139mCharacter:\033[0m ";
	std::string	name = this->getName();
	if (index < 0 || index >= 4 || !(this->_inventory)[index]) {
		std::cout << "nothing found to use at index " << index << std::endl;
		return ;
	}
	std::cout << name;
	((this->_inventory)[index])->use(target);
}

AMateria	*Character::getMateria(int index) {
	return (this->_inventory)[index];
}
