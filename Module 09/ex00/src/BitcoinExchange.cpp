#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char **argv) :  argv(argv) {
	//std::cout << "BitcoinExchange constructor called for file => " << this->argv[1] << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	//std::cout << "BitcoinExchange destructor called for file => " << this->argv[1] << std::endl;
	this->fdInput.close();
	this->fdData.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	std::cout << "BitcoinExchange assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

int BitcoinExchange::parse() {
	if (!regex_match(this->argv[1], std::regex("(.*)(.txt)"))) {
		out << "\033[31mError: wrong file extension => " << this->argv[1] << "\033[0m" << el;
		return (0);
	}
	if (!regex_match(this->argv[2], std::regex("(.*)(.csv)"))) {
		out << "\033[31mError: wrong file extension => " << this->argv[2] << "\033[0m" << el;
		return (0);
	}
	return (1);
}

int BitcoinExchange::open() {
	this->fdInput.open(this->argv[1]);
	this->fdData.open(this->argv[2]);
	if (!this->fdInput.is_open()) {
		out << "\033[31mError: could not open file => " << this->argv[1] << "\033[0m" << el;
		return (0);
	}
	if (!this->fdData.is_open()) {
		out << "\033[31mError: could not open file => " << this->argv[2] << "\033[0m" << el;
		return (0);
	}
	return (1);
}

std::string trimDate(std::string str) {
	std::string value;
	size_t pos = str.find('|');
	value = str.substr(0, pos);
  value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
	value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
	return (value);
}

std::string trimValue(std::string str) {
	std::string value;
	size_t pos = str.find('|');
	if (pos != std::string::npos) {
		value = str.substr(pos + 1);
    value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
		value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
  }
	return (value);
}

int parseDate(std::string date, std::string str) {
	std::istringstream ss(date);
  std::string year, month, day;
	std::getline(ss, year, '-');
  std::getline(ss, month, '-');
  std::getline(ss, day);

	if (std::stoll(year) < 2009 || std::stoll(year) > 2022) {
		out << "\033[31mError: invalid year " << str << "\033[0m" << el;
		return (0);
	}
	if (std::stoll(month) < 0 || std::stoll(month) > 12) {
		out << "\033[31mError: invalid month " << str << "\033[0m" << el;
		return (0);
	}
	if (std::stoll(day) < 0 || std::stoll(day) > 31) {
		out << "\033[31mError: invalid day " << str << "\033[0m" << el;
		return (0);
	}
	return (1);
}

int parseValue(std::string value, std::string str) {
	if (value == "")	{
		out << "\033[31mError: no value provided => " << str << "\033[0m" << el;
		return (0);
	}
	if (std::stoll(value) < 0 || std::stoll(value) > 2147483647) {
		out << "\033[31mError: invalid value => " << str << "\033[0m" << el;
		return (0);
	}
	return (1);
}

int parseInput(std::string str, std::string *date, std::string *value) {
	*date = trimDate(str);
	*value = trimValue(str);
	if (!parseDate(*date, str))
		return (0);
	if (!parseValue(*value, str))
		return (0);
	return (1);
}

float getValue(std::string str) {
	size_t commaPos = str.find(',');
	if (commaPos != std::string::npos) {
		std::string afterComma = str.substr(commaPos + 1);
		return (stof(afterComma));
	}
	out << "\033[31mError: invalid line => " << str << "\033[0m" << el;
	return (-1);
}

void BitcoinExchange::search(int i) {
	std::string line;
	float nbr;
	this->fdData.clear();
  this->fdData.seekg(0);
	while (getline(this->fdData, line)) {
		if (line.find(this->date[i]) != std::string::npos) {
			nbr = getValue(line);
			if (nbr == -1)
				return;
			out << "\033[32m" << this->date[i] << " => " << this->value[i] << " = " << nbr * stof(this->value[i]) << "\033[0m" << el;
		}
	}
}

void BitcoinExchange::initInput() {
	std::string str;
	std::string date;
	std::string value;
	int i = 0;
	while (getline(this->fdInput, str)) {
		if (parseInput(str, &date, &value)) {
			this->date.push_back(date);
			this->value.push_back(value);
			this->search(i);
			//print(this->date.at(i));
			//print(this->value.at(i));
			i++;
		}
	}	
}