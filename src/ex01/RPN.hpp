/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:28:38 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/21 14:15:19 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stack>
#include <list>
#include <cstdlib>

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
		std::stack< double, std::list<double> > _numbers;
		long _num;
	public:
		RPN();
		RPN(const RPN &copyObj);
		RPN &operator=(const RPN &assignCopy);
		~RPN();

		void	storeNumbers(const std::string &expression);
		bool	isValidNumber(const std::string &token);
		double	calculateExpression(double num1, double num2, int expression);
};

int 	getOperator(const std::string &token);
bool	isOperator(const std::string &token);
bool	emptyWhitespace(const char *str);

#endif // RPN_HPP