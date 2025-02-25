#pragma once

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	public:
		Data();
		~Data();
		Data(const Data &other);
		Data &operator=(const Data &other);
};

#endif