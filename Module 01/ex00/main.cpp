#include "Zombie.hpp"

int main (int argc, char **argv) {
    std::string zombie1 = "Albert";
    std::string zombie2 = "Robert";
    std::string zombie3 = "Alfred";

    if (argc < 2) {
        randomChump(zombie1);
        randomChump(zombie2);
        randomChump(zombie3);
    } else {
        for (int i = 1; i < argc; i++) {
            randomChump(argv[i]);
        }
    }
    return 0;
}