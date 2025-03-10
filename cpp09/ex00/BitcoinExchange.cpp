#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream infile("data.csv");
	if (!infile.is_open())
		throw std::invalid_argument("Cannot open data.csv");
	std::string line;
	getline(infile, line);
	while (getline(infile, line)) {
		try {
			std::string key = setKey(line);
			float value = setValue(line);
			_data[key] = value;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	infile.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
	if (this != &other)
		this->_data = other._data;
	return *this;
}

std::string BitcoinExchange::setKey(const std::string &line) {
	size_t pos = line.find(',');
	return line.substr(0, pos);
}

float BitcoinExchange::setValue(const std::string &line) {
	size_t pos = line.find(',');
	std::string value = line.substr(pos + 1);
	for (size_t i = 0; i < value.size(); i++) {
		if (std::isdigit(value[i]) == 0 && value[i] != '.')
			throw std::invalid_argument("Invalid value: " + value);
	}
	return std::strtof(value.c_str(), 0);
}

std::string BitcoinExchange::getKey(const std::string &line) {
	size_t pos = line.find('|');
	if (pos == std::string::npos)
		throw std::invalid_argument("Error: bad input => " + line);
	std::string date("0000-00-00");
	struct tm tm;
	std::string key = line.substr(0, pos);
	if (strptime(line.c_str(), "%Y-%m-%d", &tm) == NULL)
		throw std::invalid_argument("Error: bad date format => " + key);
	return key;
}

float BitcoinExchange::getValue(const std::string &line) {
	size_t pos = line.find('|');
	if (pos == std::string::npos)
		throw std::invalid_argument("Error: bad input => " + line);
	std::string value = line.substr(pos + 2);
	for (size_t i = 0; i < value.size(); i++) {
		if (std::isdigit(value[i]) == 0 && value[i] == '-')
			throw std::invalid_argument("Error: not a positive number.");
		if (std::isdigit(value[i]) == 0 && value[i] != '.')
			throw std::invalid_argument("Invalid value: " + value);
		
	}
	float val = std::strtof(value.c_str(), 0);
	if (val >= 1000)
		throw std::invalid_argument("Error: too large a number. ");
	return val;
}

void BitcoinExchange::run(const std::string &file) {
	std::ifstream infile(file);
	if (!infile.is_open())
		throw std::invalid_argument("Cannot open " + file);
	std::string line;
	getline(infile, line);
	while (getline(infile, line)) {
		try {
			std::string key = getKey(line);
			float value = getValue(line);
			std::map<std::string, double>::iterator it = _data.lower_bound(key);
			if (it == _data.end())
				throw std::invalid_argument("Error: no data for this date.");
			if (it->first != key)
				it--;
			std::cout << key << "=> " << value << " = " << value * it->second << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	infile.close();
}