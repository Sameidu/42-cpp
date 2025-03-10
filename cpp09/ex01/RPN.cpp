#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
	(void)other;
	return *this;
}

void RPN::checkArg(const std::string &op) {
	for (size_t i = 0; i < op.size(); i++) {
		if (!isdigit(op[i]) && !isspace(op[i]) && op[i] != '+' && op[i] != '-' && op[i] != '*' && op[i] != '/')
			throw std::invalid_argument("Invalid character in the expression");
		if (isspace(op[i]))
			continue;
		if (isdigit(op[i])) {
			std::string num;
			while (isdigit(op[i])) {
				num += op[i];
				i++;
			}
			std::stringstream ss(num);
			int n;
			ss >> n;
			if (n < 10 && n >= 0)
				_stack.push(n);
			else
				throw std::invalid_argument("Only numbers less than 10 or greater than 0 are allowed");
		}
		if ((op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/') && (isspace(op[i + 1]) || i + 1 == op.size())) {
			if (_stack.size() < 2)
				throw std::invalid_argument("Not enough numbers in the stack");
			operate(op[i]);
		}
	}
	std::cout << "Result: " << _stack.top() << std::endl;
}

void	RPN::operate(const char &op) {
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	if (op == '+')
		_stack.push(b + a);
	else if (op == '-')
		_stack.push(b - a);
	else if (op == '*')
		_stack.push(b * a);
	else if (op == '/') {
		if (a == 0 || b == 0)
			throw std::invalid_argument("Division by zero");
		_stack.push(b / a);
	}
}