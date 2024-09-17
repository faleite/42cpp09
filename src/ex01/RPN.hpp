/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:28:38 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/17 22:42:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stack>

enum tokens
{
	ADD = 1,
	SUB,
	DIV,
	MULT
};

class RPN
{
	private:
		std::stack<int> numbers;
	public:
		RPN();
		RPN(const RPN &copyObj);
		RPN &operator=(const RPN &assignCopy);
		~RPN();

		void	storeNumbers(const std::string &expression);
		// int		isValidNumber();
		int		calculateExpression();
};

// CANONICAL FORM

RPN::RPN() {}

RPN::RPN(const RPN &copyObj)
{
	*this = copyObj;
}

RPN &RPN::operator=(const RPN &assignCopy)
{
	(void)assignCopy;
	return(*this);	
}

RPN::~RPN() {}

// UTILS FUNCTIONS

bool isValidNumber(const std::string &token)
{
	size_t i = -1;
	
	while (token[++i])
	{
		if (i > 0 || !isdigit(token[i]))
			return (false);
	}
	return (true);
}

// CLASS FUNCTIONS

void RPN::storeNumbers(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;
	
	while (ss >> token)
	{
		int num = isValidNumber(token);
		std::cout << num << "|"; 
	}
	std::cout << "\n";
}

// int	RPN::isValidNumber()
// {
// 	return (0);
// }

int	RPN::calculateExpression()
{
	return (0);
}


#endif // RPN_HPP