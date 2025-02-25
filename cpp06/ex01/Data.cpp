#include "Data.hpp"

Data::Data() : _data(0) {}

Data::~Data() {}

Data::Data(int data) : _data(data) {}

Data::Data(const Data &other) {
	*this = other;
}

Data &Data::operator=(const Data &other) {
	_data = other._data;
	return *this;
}