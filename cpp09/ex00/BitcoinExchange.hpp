#pragma once

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <exception>


class BitcoinExchange {
	private:
		std::map<std::string, double> _data;
		
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);

		void run(const std::string &file);
		std::string setKey(const std::string &line);
		float setValue(const std::string &line);
		std::string getKey(const std::string &line);
		float getValue(const std::string &line);
};

#endif