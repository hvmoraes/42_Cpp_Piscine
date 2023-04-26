#include "HumanB.hpp"

HumanB::HumanB(std::string nameArg) {
    name = nameArg;
};

HumanB::~HumanB() {

};

void HumanB::attack() {
    std::cout << name << " attacks with their weapon " << weapon->getType() << std::endl;
};

void HumanB::setWeapon(Weapon *weaponArg) {
    weapon = weaponArg;
};