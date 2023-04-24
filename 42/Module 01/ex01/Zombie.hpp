#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string.h>
#include <iostream.h>

Class Zombie {
    private:
        std::string name;
        
    public:
        Zombie(std::string nameArg);
        ~Zombie(void);
        void announce(void);
}

Zombie *newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif