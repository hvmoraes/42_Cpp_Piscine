#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

class Zombie {
    private:
        std::string name;
        
    public:
        Zombie(std::string nameArg);
				Zombie();
        ~Zombie(void);
        void announce(void);
				void setName(std::string nameArg);
				void getName();
				//int index;
};

Zombie *zombieHorde(int N, std::string name);

#endif