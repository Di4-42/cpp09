#pragma once

#include <iostream>
#include <stdexcept>
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> _stack;

		void applyOperator(char op);

	public:
		RPN();
		RPN(const RPN& source);
		RPN& operator=(const RPN& source);
		~RPN();

		int evaluate(const std::string& expression);
};
