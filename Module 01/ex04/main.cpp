#include "sed.hpp"

void myReplace(std::string *line, std::string replace, std::string with) {
	size_t i;

	while ((i = (*line).find(replace)) != std::string::npos) {
		(*line).erase(i, replace.length());
		(*line).insert(i, with);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 4 || !argv[2][0] || !argv[3][0]) {
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
			return -1;
	}

	std::ifstream inFile(argv[1]);
	if (!inFile.is_open()) {
		std::cout << "Couldn't open file " << argv[1] << std::endl;
		return -1;
	}

	std::string fileName = argv[1];
	fileName += ".replace";
	std::ofstream outFile(fileName.c_str());
	if (!outFile.is_open()) {
		std::cout << "Couldn't open file " << fileName << std::endl;
		return -1;
	}

	std::string lineRead;
	std::string replace = argv[2];
	std::string with = argv[3];
	while (std::getline(inFile, lineRead)) {
		myReplace(&lineRead, replace, with);
		if (!std::cin.eof()) {
			outFile << lineRead << std::endl;
		}
	}

	outFile.close();
	inFile.close();
}