#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::~Weapon() {

}

const std::string *getType() {
    return(type);
}

void setType(std::string typeArg) {
    type = typeArg;
}