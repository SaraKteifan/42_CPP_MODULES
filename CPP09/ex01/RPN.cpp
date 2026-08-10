#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN()
{}

bool	RPN::isOperator(const std::string& token)
{
	if (token == "+"
		|| token == "-"
		|| token == "*"
		|| token == "/" )
		return (true);

	return (false);
}

int	RPN::applyOperator(int left, int right, char op)
{
	if (op == '+')
		return (left + right);
	else if (op == '-')
		return (left - right);
	else if (op == '*')
		return (left * right);
	else if (op == '/')
		return (left / right);

	throw std::runtime_error("Invalid operator.");
}

void	RPN::evaluateExpression(const std::string& exp)
{
	_stack = std::stack<int>();

	std::istringstream	iss(exp);
	std::string			token;

	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			_stack.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Invalid expression.");
			int	right = _stack.top();
			_stack.pop();
			int	left = _stack.top();
			_stack.pop();
			char	op = token[0];
			if (op == '/' && right == 0)
				throw std::runtime_error("Division by zero.");
			_stack.push(applyOperator(left, right, op));
		}
		else
				throw std::runtime_error("Invalid expression.");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression.");
	
	std::cout << _stack.top() << std::endl;
}
