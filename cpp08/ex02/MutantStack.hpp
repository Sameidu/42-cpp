#pragma once

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(MutantStack const &other) { *this = other; };
		MutantStack &operator=(MutantStack const &other) { (void)other; return *this; };

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return std::stack<T>::c.begin(); };
		iterator end() { return std::stack<T>::c.end(); };

		const_iterator begin() const { return std::stack<T>::c.begin(); };
		const_iterator end() const { return std::stack<T>::c.end(); };

		reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); };
		reverse_iterator rend() { return std::stack<T>::c.rend(); };

		const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); };
		const_reverse_iterator rend() const { return std::stack<T>::c.rend(); };
};

#endif