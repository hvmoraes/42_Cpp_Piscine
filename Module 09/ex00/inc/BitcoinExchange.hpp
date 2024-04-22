#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <map>
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
		std::map<std::string, std::string> data;
		char **argv;

		BitcoinExchange(char **argv);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);

		int parse();
		int open();
		int	header();
		void initInput();
		void search(std::string date, std::string value);
};

#endif