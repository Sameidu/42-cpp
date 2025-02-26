#include "Array.hpp"

int main() {
	int * a = new int();
	std::cout << "a: " << a << " *a: " << *a << std::endl;
	delete a;
}