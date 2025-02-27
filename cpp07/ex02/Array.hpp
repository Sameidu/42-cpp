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

		T &operator=(const Array &other);
		T &operator[](int index);

		unsigned int size() const;

		class OutOfRange : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif