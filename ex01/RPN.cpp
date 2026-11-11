#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN& source) : _stack(source._stack)
{
	std::cout << "Copy constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN& source)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &source)
	{
		_stack = source._stack;
	}
	return *this;
}

RPN::~RPN()
{
	std::cout << "Destructor called" << std::endl;
}

void RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: 2 nombre min requis");

							 //8 2 - | stack = [8, 2]
	int b = _stack.top();    // b = 2 | pile = [8, 2]
	_stack.pop();		     // pile = [8]

	int a = _stack.top();    // a = 8
	_stack.pop();			// pile = []

	if (op == '/' && b == 0)
		throw std::runtime_error("Error: tpp diviser par 0 poto"); // !/0

	int result;
	switch(op)
	{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		default:
			throw std::runtime_error("Error: invalid operator");
	}
	_stack.push(result);
}

int	RPN::evaluate(const std::string& expression)
{
	while(!_stack.empty())
		_stack.pop();
	
	for(size_t i = 0; i < expression.size(); i++)
	{
		char c = expression[i];

		if (c == ' ')
			continue;
		if (c >= '0' && c <= '9')
		{
			if (i + 1 < expression.size() && expression[i + 1] >= '0'
				&& expression[i + 1] <= '9')
				throw std::runtime_error("Error: only singe digit number are allowed");
			_stack.push(c - '0');  // - '48';
		} 
		else if (c == '+' || c == '-' || c == '*' || c == '/')
			applyOperator(c); // op
		else
			throw std::runtime_error("Error: invalid character");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: expression must produce exactly one result");
	return _stack.top();
}	