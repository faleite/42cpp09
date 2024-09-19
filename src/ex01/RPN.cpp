/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:28:38 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/19 17:51:42 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// CANONICAL FORM

RPN::RPN(): _num(0) {}

RPN::RPN(const RPN &copyObj): _numbers(copyObj._numbers), _num(copyObj._num)
{
	*this = copyObj;
}

RPN &RPN::operator=(const RPN &assignCopy)
{
	if (this != &assignCopy)
	{
		_numbers = assignCopy._numbers;
		_num = assignCopy._num;
	}
	return(*this);	
}

RPN::~RPN() {}

// CLASS FUNCTIONS

bool RPN::isValidNumber(const std::string &token)
{
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (!std::isdigit(token[i]) && !(i == 0 && 
			(token[i] == '-' || token[i] == '+') && token.size() > 1))
			return (false);
	}
	
	this->_num = std::strtol(token.c_str(), NULL, 10);
	// Confirmar
	if (!(this->_num >= -9 && this->_num <= 9))
		return (false);
	return (true);
}

void RPN::storeNumbers(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;
	
	while (ss >> token)
	{
		if (this->isValidNumber(token))
			this->_numbers.push(this->_num);
		else if (isOperator(token))
		{
			if (_numbers.size() < 2)
				throw std::runtime_error("Error: Invalid expression");
			double num2 = _numbers.top();
			_numbers.pop();
			double num1 = _numbers.top();
			_numbers.pop();
			double result = this->calculateExpression(num1, num2, getOperator(token));
			_numbers.push(result);
		}
		else
			throw std::runtime_error("Error: Invalid expression");
	}
	if (_numbers.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
	std::cout << _numbers.top() << std::endl;
}

double	RPN::calculateExpression(double num1, double num2, int expression)
{
	switch (expression)
	{
		case ADD:
			return (num1 + num2);
		case SUB:
			return (num1 - num2);
		case DIV:
			if (num2 == 0)
				throw std::runtime_error("Error: Division by Zero");
			return (num1 / num2);
		case MULT:
			return (num1 * num2);
		default:
			throw std::runtime_error("Error: Invalid expression");
	}
}
