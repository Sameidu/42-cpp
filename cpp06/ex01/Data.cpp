#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(const Data &other) {
	*this = other;
}

Data &Data::operator=(const Data &other) {
	(void)other;
	return *this;
}