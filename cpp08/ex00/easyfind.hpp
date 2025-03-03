#pragma once

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyFind(T &containter, int n) {
	typename T::iterator tf = std::find(containter.begin(), containter.end(), n);
	if (tf == containter.end())
		throw std::logic_error("Element not found in container");
	return tf;
}

#endif