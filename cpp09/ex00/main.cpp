#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc = BitcoinExchange();
		btc.run(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}