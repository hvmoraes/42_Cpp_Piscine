#include <iostream.h>
#include <string.h>

Class Weapon {
    private:
        std::string type;

    public:
        const std::string *getType();
        void setType(std::string type);
}