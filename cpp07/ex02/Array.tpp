#include "Array.hpp"

template <typename T>
Array<T>::Array() : _obj(new T[0]), _size(0) {};

template <typename T>
Array<T>::~Array() { delete [] _obj; };

template <typename T>
Array<T>::Array(unsigned int size) : _obj(new T[size]), _size(size) {};

template <typename T>
Array<T>::Array(const Array &other) : _obj(new T[other._size]), _size(other._size) {
	for (size_t i = 0; i < _size; i++)
		this->_obj[i] = other._obj[i];
};

template <typename T>
Array<T>&Array<T>::operator=(const Array &other) {
	if (this == &other)
		return *this;
	delete [] _obj;
	_size = other._size;
	_obj = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_obj[i] = other._obj[i];
	return *this;
};

template <typename T>
Array<T>&Array<T>::operator[](unsigned int index) {
	if (index > _size)
		throw std::cout << "Out of range access" << std::endl;
	return _obj[index];
};

template <typename T>
unsigned int Array<T>::size() const { return (_size); };