#pragma once

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stack>
#include <iterator>
#include <exception>

class RPN {
	private:
		std::stack<int> _stack;
		
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		void checkArg(const std::string &op);
		void operate(const char &op);
};

#endif