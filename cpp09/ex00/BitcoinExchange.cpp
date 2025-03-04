#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream infile("data.csv");
	if (!infile.is_open())
		throw std::invalid_argument("Cannot open data.csv");
	std::string line;
	while (getline(infile, line)) {
		std::cout << line << std::endl;
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

void BitcoinExchange::run(const std::string &file) {
	std::ifstream infile(file);
	if (!infile.is_open())
		throw std::invalid_argument("Cannot open " + file);
	std::string line;
	while (getline(infile, line)) {
		std::cout << line << std::endl;
	}
	infile.close();
}