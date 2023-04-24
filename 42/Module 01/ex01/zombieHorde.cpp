#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombies[i]->zombieName = name;
        zombies[i]->announce();
        delete(zombie[i]);
    }
}
