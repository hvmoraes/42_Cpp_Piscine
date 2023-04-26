#include <iostream>
#include <string.h>
#pragma once

class Weapon {
    private:
        std::string type;

    public:
        const std::string getType();
        void setType(std::string type);
				Weapon(std::string type);
				~Weapon();
};