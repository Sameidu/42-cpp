#pragma once

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t len, F f) {
	if (!array || !f) {
		std::cerr << "Error: invalid array or function pointer" << std::endl;
		return;
	}
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif