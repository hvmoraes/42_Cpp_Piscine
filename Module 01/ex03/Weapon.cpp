#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	setType(type);
};

Weapon::~Weapon() {

};

const std::string Weapon::getType() {
    return(type);
};

void Weapon::setType(std::string typeArg) {
    type = typeArg;
};