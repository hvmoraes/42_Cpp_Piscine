#include "HumanA.hpp"

HumanA::HumanA(std::string nameArg, Weapon *weaponArg) {
    name = nameArg;
    weapon = weaponArg;
};

HumanA::~HumanA() {

};

void HumanA::attack() {
    std::cout << name << " attacks with their weapon " << weapon->getType() << std::endl;
};