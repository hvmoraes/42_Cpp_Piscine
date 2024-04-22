#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 3)
		print("Usage: ./btc file.txt data.csv");
	else {
		BitcoinExchange bitcoin(argv);
		if (!bitcoin.parse())
			return (0);
		if (!bitcoin.open())
			return (0);
		if (!bitcoin.header())
			return (0);
		bitcoin.initInput();
	}
	return (1);
}