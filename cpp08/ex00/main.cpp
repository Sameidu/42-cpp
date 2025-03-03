#include "easyfind.hpp"

int main() {
	try {
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::vector<int>::iterator it = easyFind(v, 3);
		std::cout << "Element found at index: " << std::distance(v.begin(), it) << std::endl;
		it = easyFind(v, 6);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		std::list<int>::iterator it = easyFind(l, 3);
		std::cout << "Element found at index: " << std::distance(l.begin(), it) << std::endl;
		it = easyFind(l, 6);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}