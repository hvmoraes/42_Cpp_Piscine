#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		print("Usage: ./pmerge [numbers]");
		return (0);
	}
	PmergeMe pmerge(argc, argv);
	if (!pmerge.sort())
		return (0);
	return (1);
}