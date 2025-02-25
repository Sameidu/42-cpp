#pragma once

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer {
	private:
		Serializer();

	public:
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif