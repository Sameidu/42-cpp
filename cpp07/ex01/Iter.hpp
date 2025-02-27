#pragma once

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*f)(T&)) {
	if (!array || !f) {
		std::cerr << "Error: invalid array or function pointer" << std::endl;
		return;
	}
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

template <typename T>
void iter(T *array, size_t len, void (*f)(const T&)) {
	if (!array || !f) {
		std::cerr << "Error: invalid array or function pointer" << std::endl;
		return;
	}
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif