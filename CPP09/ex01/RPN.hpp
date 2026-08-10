#ifndef	RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int>	_stack;
		bool	isOperator(const std::string& token);
		int		applyOperator(int left, int right, char op);
	public:
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();
		void	evaluateExpression(const std::string& exp);
};

#endif
