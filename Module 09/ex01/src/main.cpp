#include "../inc/RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		print("Usage: ./rpn \"expression\"");
		return (0);
	}
	RPN rpn(argv[1]);
	if (!rpn.initStack())
		return (0);
	return (1);
}