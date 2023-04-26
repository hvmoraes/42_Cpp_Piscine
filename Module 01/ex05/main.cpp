#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			harl.complain(argv[i]);
		}
		return 0;
	}
	std::cout << "Usage: " << argv[0] << " <complain>, <complain>, etc..." << std::endl;
}