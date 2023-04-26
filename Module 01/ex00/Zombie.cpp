#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    zombieName = name;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " + zombieName + " died..." << std::endl;
}

void Zombie::announce(void) {
    std::cout << zombieName + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
