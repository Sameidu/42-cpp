#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2)
		throw std::invalid_argument("Usage: ./bitcoin [filename]");
	try {
		BitcoinExchange btc = BitcoinExchange();
		btc.run(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}