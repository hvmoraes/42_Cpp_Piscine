#include "Zombie.hpp"

int main(int argc, char **argv) {
	int N = 4;
	std::string name = "Brian";
	Zombie *zombie;
	if (argc == 2) {
		zombie = zombieHorde(atoi(argv[1]), name);
	} else if (argc == 3) {
		zombie = zombieHorde(atoi(argv[1]), argv[2]);
	} else {
		zombie = zombieHorde(N, name);
	}
	//std::cout << zombie->index << std::endl;
	//delete[]zombie;

	for (int i = 0; i < 2; i++) {
		if (i != 2)
			delete(&zombie[i]);
	}
	return 0;
}