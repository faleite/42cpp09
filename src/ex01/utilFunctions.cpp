/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:46:42 by faaraujo          #+#    #+#             */
/*   Updated: 2024/09/19 17:46:59 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// UTILS FUNCTIONS

int getOperator(const std::string &token)
{
	if (token == "+")
		return (ADD);
	if (token == "-")
		return (SUB);
	if (token == "/")
		return (DIV);
	return (MULT);
}

bool isOperator(const std::string &token)
{
	std::string str = "+-*/";
	return (token.size() == 1 && str.find(token) != std::string::npos);
}

bool emptyWhitespace(const char *str)
{
	if (str == NULL)
		return (true);
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (false);
		str++;
	}
	return (true);
}
