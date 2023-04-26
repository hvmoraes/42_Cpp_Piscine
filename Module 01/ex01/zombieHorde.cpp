#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string nameArg) {
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombies[i].setName(nameArg);
        zombies[i].announce();
				//zombies[i].index = i;
    }
		return zombies;
}
