#include "HumanA.hpp"

HumanA::HumanA(std::string nameArg) {
    name = nameArg;
    weapon = weaponArg;
}

void HumanA::attack() {
    std::cout << name << " attacks with their weapon " << weapon->type << endl;
}

void HumanB::setWeapon(Weapon *weaponArg) {
    weapon = weaponArg;
}