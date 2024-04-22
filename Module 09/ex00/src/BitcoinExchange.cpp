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
	if (std::string(argv[1]).find(".txt") == std::string::npos && std::string(argv[1]).find(".csv") == std::string::npos) {
		out << "\033[31mError: wrong file extension => " << this->argv[1] << "\033[0m" << el;
		return (0);
	}
	if (std::string(argv[2]).find(".csv") == std::string::npos) {
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

std::string trimHeader(std::string header) {
	std::string result = header;
	result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
	result.erase(0, result.find_first_not_of(" \t\n\r\f\v"));
	return (result);
}

std::string putOneSpace(std::string str) {
	std::istringstream iss(str);
	std::ostringstream oss;
	std::string word;

	while (iss >> word) {
			oss << word << ' ';
	}

	std::string result = oss.str();
	return (result);
}

int	BitcoinExchange::header() {
	std::string header;

	getline(this->fdInput, header);
	header = putOneSpace(header);
	header = trimHeader(header);
	out << "\"" << header << "\"" << el;
	if (header != "date | value") {
		out << "\033[31mError: No header (\"date | value\") present at start of file => " << this->argv[1] << "\033[0m" << el;
		return (0);
	}
	return (1);
}

std::string trimDate(std::string date) {
	std::string result;
	size_t pos = date.find('|');
	result = date.substr(0, pos);
  result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
	result.erase(0, result.find_first_not_of(" \t\n\r\f\v"));
	return (result);
}

std::string trimValue(std::string value) {
	std::string result;
	size_t pos = value.find('|');
	if (pos != std::string::npos) {
		result = value.substr(pos + 1);
    result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
		result.erase(0, result.find_first_not_of(" \t\n\r\f\v"));
  }
	return (result);
}

int parseDate(std::string date, std::string str) {
	std::istringstream ss(date);
  std::string year, month, day;
	std::getline(ss, year, '-');
  std::getline(ss, month, '-');
  std::getline(ss, day);

	if (date == "") {
		out << "\033[31mError: No date provided\033[0m" << el;
		return (0);
	}
	if (atoi(year.c_str()) < 2009 || atoi(year.c_str()) > 2022) {
		out << "\033[31mError: Invalid year " << trimDate(putOneSpace(str)) << "\033[0m" << el;
		return (0);
	}
	if (atoi(month.c_str()) < 0 || atoi(month.c_str()) > 12) {
		out << "\033[31mError: Invalid month " << trimDate(putOneSpace(str)) << "\033[0m" << el;
		return (0);
	}
	if (atoi(day.c_str()) < 0 || atoi(day.c_str()) > 31) {
		out << "\033[31mError: Invalid day " << trimDate(putOneSpace(str)) << "\033[0m" << el;
		return (0);
	}
	return (1);
}

int parseValue(std::string value, std::string str) {
	if (value == "")	{
		out << "\033[31mError: No value provided\033[0m" << el;
		return (0);
	}
	if (atof(value.c_str()) < 0 || atof(value.c_str()) > 1000) {
		out << "\033[31mError: Invalid value => " << trimValue(putOneSpace(str)) << "\033[0m" << el;
		return (0);
	}
	return (1);
}

int parseInput(std::string str, std::string *date, std::string *value) {
	*date = putOneSpace(*date);
	*date = trimDate(str);
	*value = putOneSpace(*value);
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
		return (atof(afterComma.c_str()));
	}
	out << "\033[31mError: Invalid line => " << str << "\033[0m" << el;
	return (-1);
}

void BitcoinExchange::search(std::string date, std::string value) {
	std::string line;
	float nbr;
	float closestLowerNbr = -1;
  std::string closestLowerDate;

	this->fdData.clear();
  this->fdData.seekg(0);
	while (getline(this->fdData, line)) {
		std::string currentDate = line.substr(0, 10);
		if (currentDate <= date) {
			if (currentDate > closestLowerDate || closestLowerDate.empty()) {
				closestLowerDate = currentDate;
				nbr = getValue(line);
				closestLowerNbr = nbr;
			}
		}
	}

	if (closestLowerNbr != -1)
		std::cout << "\033[32m" << closestLowerDate << " => " << value << " = " << closestLowerNbr * atof(value.c_str()) << "\033[0m" << std::endl;
	else
		std::cout << "\033[31mError: No closer date found in DataBase => " << trimDate(putOneSpace(date)) << "\033[0m" << std::endl;
}

void BitcoinExchange::initInput() {
	std::string str;
	std::string date;
	std::string value;
	int i = 0;
	while (getline(this->fdInput, str)) {
		if (parseInput(str, &date, &value)) {
			this->data.insert(std::make_pair(date, value));
			this->search(date, value);
			i++;
		}
	}
}