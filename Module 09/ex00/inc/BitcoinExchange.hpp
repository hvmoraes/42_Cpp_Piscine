#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#define print(x) std::cout << x << std::endl
#define out std::cout
#define el std::endl

class BitcoinExchange {
	private:
		
	protected:
		
	public:
		std::ifstream fdInput;
		std::ifstream fdData;
		std::vector<std::string> date;
		std::vector<std::string> value;
		char **argv;

		BitcoinExchange(char **argv);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);

		int parse();
		int open();
		void initInput();
		void search(int i);
};

#endif