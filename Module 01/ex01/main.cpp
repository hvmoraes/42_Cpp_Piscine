#include "Zombie.hpp"

int main(int argc, char **argv) {
	int N = 4;
	std::string name = "Brian";
	Zombie *zombie = new Zombie[N];
	if (argc == 2) {
		zombie = zombieHorde(std::stoi(argv[1]), name);
	} else if (argc == 3) {
		zombie = zombieHorde(std::stoi(argv[1]), argv[2]);
	} else {
		zombie = zombieHorde(N, name);
	}
	//std::cout << zombie->index << std::endl;
	delete[]zombie;
	return 0;
}