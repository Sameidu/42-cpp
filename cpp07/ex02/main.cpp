#include "Array.hpp"

int main() {
	std::cout << "===== Let's test the Array class =====" << std::endl;
	try {
		std::cout << "========================= TEST ACCESS OUT OF RANGE =========================" << std::endl;
		std::cout << "Now we will create an array of 7 strings and attemp an invalid access" << std::endl;
		Array <std::string> si(7);
		std::cout << "Size of array: " << si.size() << std::endl;
		for (size_t i = 0; i < si.size(); i++) {
			si[i] = "String number " + std::to_string(i);
			std::cout << si[i] << std::endl;
		}
		std::cout << "This is a valid access si[6]: " << si[6] << std::endl;
		std::cout << "This is an invalid acces that will throw an exception si[-3]: " << si[-3] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl
		<< "============================================================================" << std::endl;
	}

	try {
		std::cout << "======================= TEST ACCESS INTO EMPTY ARRAY =======================" << std::endl;
		std::cout << "Now we will create an empty array and attempt an invalid access" << std::endl;
		Array <std::string> si;
		std::cout << "This is an invalid access because the array is empty si[0] " << si[0] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl
		<< "============================================================================" << std::endl;
	}

	try {
		std::cout << "========================== TEST COPY ARRAY =========================" << std::endl;
		std::cout << "Now we will create an array of 7 integers and copy it into a new one" << std::endl;
		Array <int> si(7);
		std::cout << "Size of original array: " << si.size() << std::endl;
		for (size_t i = 0; i < si.size(); i++) {
			si[i] = i;
			std::cout << si[i] << std::endl;
		}
		Array <int> cpy(si);
		std::cout << "Size of copy array: " << cpy.size() << std::endl;
		std::cout << "Now we will change the first element of the copied array and print both" << std::endl;
		std::cout << "Copy array: " << std::endl;
		cpy[0] = 42;
		for (size_t i = 0; i < cpy.size(); i++) {
			std::cout << cpy[i] << std::endl;
		}
		std::cout << "Original array: " << std::endl;
		for (size_t i = 0; i < si.size(); i++) {
			std::cout << si[i] << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl
		<< "============================================================================" << std::endl;
	}
	std::cout << "============================= THE END ================================" << std::endl;
}