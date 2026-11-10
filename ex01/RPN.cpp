#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN& other)
{
	std::cout << "Copy constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
	{}
	return *this;
}

RPN::~RPN()
{
	std::cout << "Destructor called" << std::endl;
}