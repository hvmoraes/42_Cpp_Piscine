#include "Zombie.hpp"

Zombie::Zombie(std::string nameArg) {
    name = nameArg;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " + name + " died..." << std::endl;
}

void Zombie::announce(void) {
    std::cout << name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}