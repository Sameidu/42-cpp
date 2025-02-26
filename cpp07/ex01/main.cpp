#include <iostream>
#include <string>
#include "Iter.hpp"

class Uwu {
	private:
		int _n;
	public:
		Uwu() : _n(42) {};
		Uwu(int n) : _n(n) {};
		~Uwu() {};
		Uwu(const Uwu &other) : _n(other._n) {};
		Uwu &operator=(const Uwu &other) {
			if (this != &other) {
				this->_n = other._n;
			}
			return *this;
		}
		int getN() const {
			return this->_n;
		}
		void setN(int n) {
			this->_n = n;
		}
		 void talk() {
			std::cout << "UwU " << getN() << std::endl;
		}
};

void	setN(Uwu &uwu) {
	static int n = 13;
	uwu = Uwu(n);
	n++;
}

void talk(Uwu &uwu) {
	uwu.talk();
}

template <typename T>
void print(T &x) {
	std::cout << x << std::endl;
}

int main() {
	std::string strarr[] = {"si", "no", "hola", "adios", "que", "tal", "uwu"};
	::iter(strarr, 7, &print);

	int intarr[] = {1, 2, 3, 4, 5};
	::iter(intarr, 5, &print);

	::iter((int*)NULL, 9, &print);

	Uwu *uwuarr = new Uwu[10];
	::iter(uwuarr, 10, setN);
	::iter(uwuarr, 10, talk);
	delete[] uwuarr;

	return 0;
}