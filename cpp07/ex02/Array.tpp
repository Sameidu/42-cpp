#include "Array.hpp"

template <typename T>
Array<T>::Array() : _obj(new T), _size(0) {};

template <typename T>
Array<T>::~Array() { delete _obj };

