#pragma once

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private:
		int	_data;
	public:
		Data();
		~Data();
		Data(int data);
		Data(const Data &other);
		Data &operator=(const Data &other);
};

#endif