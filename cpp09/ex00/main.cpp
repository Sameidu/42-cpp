#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	try {
		if (ac != 2)
			throw std::invalid_argument("Usage: ./bitcoin [filename]");
		BitcoinExchange btc = BitcoinExchange();
		btc.run(av[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}