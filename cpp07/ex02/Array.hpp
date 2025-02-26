#pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template <typename T>
class Array {
	private:
		T *_obj;
		unsigned int _size;

	public:
		Array();
		~Array();
		Array(unsigned int size);
		Array(const Array &other);

		Array &operator=(const Array &other);
		Array &operator[](unsigned int index);

		unsigned int size() const;
};

#include "Array.tpp"

#endif