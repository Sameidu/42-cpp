#include "Array.hpp"

int main() {
	int * a = new int();
	std::cout << "a: " << a << " *a: " << *a << std::endl;
	delete a;

	Array <char> si(1312);
	std::cout << "Size of array: " <<si.size() << std::endl;
}